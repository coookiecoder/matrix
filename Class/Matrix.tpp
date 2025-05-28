#ifndef MATRIX_MATRIX_TPP
#define MATRIX_MATRIX_TPP

#include <iostream>
#include <iomanip>
#include <cmath>

template<class K>
class Matrix {
    protected:
        K **data;
        unsigned line;
        unsigned column;
        bool vector;
    public:
        Matrix();
        Matrix(unsigned line, unsigned column);
        Matrix(unsigned line, unsigned column, const std::initializer_list<K> &value);
        Matrix(Matrix const &copy);
        Matrix(Matrix &&copy) noexcept;

        Matrix& operator=(const Matrix &copy);
        Matrix& operator=(Matrix &&copy) noexcept;

        virtual ~Matrix();

        void set(unsigned line_set, unsigned column_set, K value);
        [[nodiscard]] K get(unsigned line_get, unsigned column_get) const;

        void add_line(Matrix<K> matrix, unsigned line);
        void subtract_line(Matrix<K> matrix, unsigned line);
        void multiply_line(Matrix<K> matrix, unsigned line);
        void divide_line(Matrix<K>, unsigned line);

        void add_line(K scale, unsigned line);
        void subtract_line(K scale, unsigned line);
        void multiply_line(K scale, unsigned line);
        void divide_line(K scale, unsigned line);

        void add_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix);
        void subtract_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix);
        void multiply_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix);
        void divide_line(Matrix<K>, K scale, unsigned line, unsigned line_matrix);

		void add_line_by_line(unsigned line_one, unsigned line_two, K scale);
		void subtract_line_by_line(unsigned line_one, unsigned line_two, K scale);
		void multiply_line_by_line(unsigned line_one, unsigned line_two, K scale);
		void divide_line_by_line(unsigned line_one, unsigned line_two, K scale);

        void swap_line(unsigned line_one, unsigned line_two);

        void add(Matrix<K> matrix);
        void subtract(Matrix<K> matrix);
        [[nodiscard]] virtual Matrix<K> multiply(Matrix<K> matrix);
        void scale(K scale);

        [[nodiscard]] K trace();
        [[nodiscard]] Matrix<K> transpose();
        [[nodiscard]] Matrix<K> row_echelon();
		[[nodiscard]] K determinant();
		[[nodiscard]] Matrix<K> inverse();
		unsigned rank();

        [[nodiscard]] unsigned get_line() const;
        [[nodiscard]] unsigned get_column() const;

        [[nodiscard]] bool is_square() const;
        [[nodiscard]] bool is_vector() const;
        [[nodiscard]] bool is_nonzero(unsigned line_find) const;
		[[nodiscard]] bool is_identity() const;

        virtual void print();

        void matrix_to_vector();
        void vector_to_matrix();

        Matrix<K> operator+(Matrix<K> const &matrix);
        Matrix<K> operator-(Matrix<K> const &matrix);
        Matrix<K> operator*(Matrix<K> const &matrix);
        Matrix<K> operator*(K scale);
};

template<class K>
std::ostream &operator<<(std::ostream &output, Matrix<K> const &input) {
    output << "is a square : " << input.is_square() << std::endl;
    output << "is a vector : " << input.is_vector() << std::endl;
    for (int line_print = 0; line_print < input.get_line(); ++line_print) {
        output << "[";
        for (int column_print = 0; column_print < input.get_column(); ++column_print) {
            if (column_print < input.get_column() - 1) {
                output << std::setw(10) << (input.get(line_print + 1, column_print + 1)) << ", ";
            } else {
                output << std::setw(10) << (input.get(line_print + 1, column_print + 1));
            }
        }
        if (line_print != input.get_line() - 1) {
            output << "]" << std::endl;
        } else {
            output << "]";
        }
    }
    if (input.get_line() == 0 && input.get_column() == 0) {
        output << "empty matrix" << std::endl;
    }
    return output;
}

template<class K>
Matrix<K>::Matrix() : line(0), column(0), vector(false) {
    this->data = nullptr;
}

template<class K>
Matrix<K>::Matrix(unsigned line, unsigned column) : line(line), column(column), vector(false) {
    this->data = new K*[line];

    for (int line_set = 0; line_set < line; ++line_set) {
        this->data[line_set] = new K[column];
    }

    for (int line_set = 0; line_set < line; ++line_set) {
        for (int column_set = 0; column_set < column; ++column_set) {
            this->data[line_set][column_set] = K();
        }
    }
}

template<class K>
Matrix<K>::Matrix(unsigned line, unsigned column, const std::initializer_list<K> &value) : line(line), column(column), vector(false) {
    this->data = new K*[line];

    for (int line_set = 0; line_set < line; ++line_set) {
        this->data[line_set] = new K[column];
    }

    auto value_iterator = value.begin();

    for (int line_set = 0; line_set < line; ++line_set) {
        for (int column_set = 0; column_set < column; ++column_set) {
            if (value_iterator != value.end()) {
                this->data[line_set][column_set] = *(value_iterator++);
            } else {
                this->data[line_set][column_set] = K();
            }
        }
    }
}

template<class K>
Matrix<K>::Matrix(Matrix const &copy) : line(copy.line), column(copy.column), vector(copy.vector) {
    this->data = new K*[copy.line];

    for (int line_set = 0; line_set < copy.line; ++line_set) {
        data[line_set] = new K[copy.column];
    }

    for (int line_copy = 0; line_copy < copy.line; ++line_copy) {
        for (int column_copy = 0; column_copy < copy.column; ++column_copy) {
            data[line_copy][column_copy] = copy.data[line_copy][column_copy];
        }
    }
}

template<class K>
Matrix<K>::Matrix(Matrix &&copy) noexcept : line(copy.line), column(copy.column), vector(copy.vector) {
    this->data = copy.data;

    copy.line = 0;
    copy.column = 0;
    copy.vector = false;
    copy.data = nullptr;
}

template<class K>
Matrix<K> &Matrix<K>::operator=(const Matrix &copy) {
    if (this != &copy) {
        this->line = copy.line;
        this->column = copy.column;
        this->vector = copy.vector;
        this->data = new K *[copy.line];

        for (int line_copy = 0; line_copy < copy.line; ++line_copy) {
            data[copy.line] = new K[copy.column];
        }

        for (int line_copy = 0; line_copy < copy.line; ++line_copy) {
            for (int column_copy = 0; column_copy < copy.column; ++column_copy) {
                data[line_copy][column_copy] = copy.data[line_copy][column_copy];
            }
        }
    }
    return *this;
}

template<class K>
Matrix<K> &Matrix<K>::operator=(Matrix &&copy) noexcept {
    if (this != &copy) {
        this->line = copy.line;
        this->column = copy.column;
        this->vector = copy.vector;
        this->data = copy.data;

        copy.line = 0;
        copy.column = 0;
        copy.vector = false;
        copy.data = nullptr;
    }
    return *this;
}

template<class K>
Matrix<K>::~Matrix() {
    for (int line_delete = 0; line_delete < this->line; ++line_delete) {
        delete [] data[line_delete];
    }

    delete [] data;
}

template<class K>
void Matrix<K>::set(unsigned line_set, unsigned column_set, K value) {
    if (line_set <= this->line && column_set <= this->column && line_set && column_set) {
        this->data[line_set - 1][column_set - 1] = value;
    } else {
        std::cout << "error while setting the data at " << line_set << " " << column_set << std::endl;
    }
}

template<class K>
K Matrix<K>::get(unsigned line_get, unsigned column_get) const {
    if (line_get <= this->line && column_get <= this->column && line_get && column_get) {
        return this->data[line_get - 1][column_get - 1];
    } else {
        std::cout << "error while getting the data at " << line_get << " " << column_get << std::endl;
        return K();
    }
}

template<class K>
void Matrix<K>::add_line(Matrix<K> matrix, unsigned line) {
    for (int column_add = 1; column_add <= this->get_column(); ++column_add) {
        this->set(line, column_add, this->get(line, column_add) + matrix.get(line, column_add));
    }
}

template<class K>
void Matrix<K>::subtract_line(Matrix<K> matrix, unsigned line) {
    for (int column_subtract = 1; column_subtract <= this->get_column(); ++column_subtract) {
        this->set(line, column_subtract, this->get(line, column_subtract) - matrix.get(line, column_subtract));
    }
}

template<class K>
void Matrix<K>::multiply_line(Matrix<K> matrix, unsigned line) {
    for (int column_multiply = 1; column_multiply <= this->get_column(); ++column_multiply) {
        this->set(line, column_multiply, this->get(line, column_multiply) * matrix.get(line, column_multiply));
    }
}

template<class K>
void Matrix<K>::divide_line(Matrix<K> matrix, unsigned line) {
    for (int column_divide = 1; column_divide <= this->get_column(); ++column_divide) {
        this->set(line, column_divide, this->get(line, column_divide) / matrix.get(line, column_divide));
    }
}

template<class K>
void Matrix<K>::add_line(K scale, unsigned line) {
    for (int column_add = 1; column_add <= this->get_column(); ++column_add) {
        this->set(line, column_add, this->get(line, column_add) + scale);
    }
}

template<class K>
void Matrix<K>::subtract_line(K scale, unsigned line) {
    for (int column_subtract = 1; column_subtract <= this->get_column(); ++column_subtract) {
        this->set(line, column_subtract, this->get(line, column_subtract) - scale);
    }
}

template<class K>
void Matrix<K>::multiply_line(K scale, unsigned line) {
    for (int column_multiply = 1; column_multiply <= this->get_column(); ++column_multiply) {
        this->set(line, column_multiply, this->get(line, column_multiply) * scale);
    }
}

template<class K>
void Matrix<K>::divide_line(K scale, unsigned line) {
    for (int column_divide = 1; column_divide <= this->get_column(); ++column_divide) {
        this->set(line, column_divide, this->get(line, column_divide) / scale);
    }
}

template<class K>
void Matrix<K>::add_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix) {
    for (int column_add = 1; column_add <= this->get_column(); ++column_add) {
        this->set(line, column_add, this->get(line, column_add) + scale * matrix.get(line_matrix, column_add));
    }
}

template<class K>
void Matrix<K>::subtract_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix) {
    for (int column_subtract = 1; column_subtract <= this->get_column(); ++column_subtract) {
        this->set(line, column_subtract, this->get(line, column_subtract) - scale * matrix.get(line_matrix, column_subtract));
    }
}

template<class K>
void Matrix<K>::multiply_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix) {
    for (int column_multiply = 1; column_multiply <= this->get_column(); ++column_multiply) {
        this->set(line, column_multiply, this->get(line, column_multiply) * (scale * matrix.get(line_matrix, column_multiply)));
    }
}

template<class K>
void Matrix<K>::divide_line(Matrix<K> matrix, K scale, unsigned line, unsigned line_matrix) {
    for (int column_divide = 1; column_divide <= this->get_column(); ++column_divide) {
        this->set(line, column_divide, this->get(line, column_divide) / (scale  * matrix.get(line_matrix, column_divide)));
    }
}

template<class K>
void Matrix<K>::add_line_by_line(unsigned line_one, unsigned line_two, K scale) {
	for (int column_add = 1; column_add <= this->get_column(); ++column_add) {
		this->set(line_one, column_add, this->get(line_one, column_add) + this->get(line_two, column_add) * scale);
	}
}

template<class K>
void Matrix<K>::subtract_line_by_line(unsigned line_one, unsigned line_two, K scale) {
	for (int column_subtract = 1; column_subtract <= this->get_column(); ++column_subtract) {
		this->set(line_one, column_subtract, this->get(line_one, column_subtract) - this->get(line_two, column_subtract) * scale);
	}
}

template<class K>
void Matrix<K>::multiply_line_by_line(unsigned line_one, unsigned line_two, K scale) {
	for (int column_multiply = 1; column_multiply <= this->get_column(); ++column_multiply) {
		this->set(line_one, column_multiply, this->get(line_one, column_multiply) * (this->get(line_two, column_multiply) * scale));
	}
}
template<class K>
void Matrix<K>::divide_line_by_line(unsigned line_one, unsigned line_two, K scale) {
	for (int column_divide = 1; column_divide <= this->get_column(); ++column_divide) {
		this->set(line_one, column_divide, this->get(line_one, column_divide) / (this->get(line_two, column_divide) * scale));
	}
}


template<class K>
void Matrix<K>::swap_line(unsigned line_one, unsigned line_two) {
    if (line_one != line_two) {
        for (int column_swap = 1; column_swap <= this->column; ++column_swap) {
            K buffer = this->get(line_one, column_swap);
            this->set(line_one, column_swap, this->get(line_two, column_swap));
            this->set(line_two, column_swap, buffer);
        }
    }
}

template<class K>
void Matrix<K>::add(Matrix<K> const matrix) {
    if (matrix.line == this->line && matrix.column == this->column) {
        for (int line_add = 0; line_add < line; ++line_add) {
            for (int column_add = 0; column_add < column; ++column_add) {
                this->data[line_add][column_add] = matrix.data[line_add][column_add] + this->data[line_add][column_add];
            }
        }
    } else {
        std::cout << "incompatible matrix" << std::endl;
        std::cout << matrix;
        std::cout << "and" << std::endl;
        std::cout << *this;
    }
}

template<class K>
void Matrix<K>::subtract(Matrix const matrix) {
    if (matrix.line == this->line && matrix.column == this->column) {
        for (int line_subtract = 0; line_subtract < line; ++line_subtract) {
            for (int column_subtract = 0; column_subtract < column; ++column_subtract) {
                this->data[line_subtract][column_subtract] = matrix.data[line_subtract][column_subtract] - this->data[line_subtract][column_subtract];
            }
        }
    } else {
        std::cout << "incompatible matrix" << std::endl;
        std::cout << matrix;
        std::cout << "and" << std::endl;
        std::cout << *this;
    }
}

template<class K>
Matrix<K> Matrix<K>::multiply(Matrix const matrix) {
    if (this->line == matrix.column && this->column == matrix.line) {
        Matrix<K> result(this->line, matrix.column);

        for (int line_multiply= 0; line_multiply < result.line; ++line_multiply) {
            for (int column_multiply = 0; column_multiply < result.column; ++column_multiply) {
                K buffer = K();
                for (int cursor = 0; cursor < this->column; ++cursor) {
                    buffer = std::fma(this->data[line_multiply][cursor], matrix.data[cursor][column_multiply], buffer);
                }
                result.set(line_multiply + 1, column_multiply + 1, buffer);
            }
        }
        return result;
    } else {
        std::cout << "incompatible matrix" << std::endl;
        std::cout << matrix;
        std::cout << "and" << std::endl;
        std::cout << *this;
        Matrix<K> result;
        return result;
    }
}

template<class K>
void Matrix<K>::scale(K scale) {
    for (int line_scale = 0; line_scale < this->line; ++line_scale) {
        for (int column_scale = 0; column_scale < this->column; ++column_scale) {
            this->data[line_scale][column_scale] *= scale;
        }
    }
}

template<class K>
K Matrix<K>::trace() {
    if (this->is_square()) {
        K result = K();

        for (int trace_index = 0; trace_index < this->get_line(); ++trace_index) {
            result += this->get(trace_index + 1, trace_index + 1);
        }

        return result;
    }
    throw std::invalid_argument("the matrix is not sqare");
}

template<class K>
Matrix<K> Matrix<K>::transpose() {
    Matrix<K> result(this->get_column(), this->get_line());

    for (int transpose_line = 1; transpose_line <= this->get_column(); ++transpose_line) {
        for (int transpose_column = 1; transpose_column <= this->get_line(); ++transpose_column) {
            result.set(transpose_line, transpose_column, this->get(transpose_column, transpose_line));
        }
    }

    return result;
}

template <class K>
Matrix<K> Matrix<K>::row_echelon()
{
	Matrix<K> result(*this);
	int column_pivot = 0;
	int row_pivot = 0;

	for (int current_column = 1; current_column <= result.get_column(); current_column++) {
		for (int current_row = 1; current_row <= result.get_line(); current_row++) {
			if (result.get(current_row, current_column)) {
				column_pivot = current_column;
				row_pivot = current_row;
				break ;
			}
		}
		if (result.get(row_pivot, current_column))
			break ;
	}

	if (row_pivot != 1)
		result.swap_line(1, row_pivot);

	for (row_pivot = 1; row_pivot <= result.get_line(); row_pivot++) {
		for (int current_row = row_pivot + 1; current_row <= result.get_line(); current_row++) {
			if (result.get(current_row, column_pivot)) {
				result.subtract_line_by_line(current_row, row_pivot, result.get(current_row, column_pivot) / result.get(row_pivot, column_pivot));
				result.set(current_row, column_pivot, 0);
			}
		}

		for (int current_column = column_pivot; current_column <= result.get_column(); current_column++) {
			if (row_pivot + 1 < result.get_line() && result.get(row_pivot + 1, current_column)) {
				column_pivot = current_column;
				break ;
			}
		}
	}

	return (result);
}

template <class K>
K Matrix<K>::determinant() {
	if (!this->is_square()) {
		throw std::invalid_argument("The matrix must be square.");
	}

	int n = this->line;
	Matrix<K> LU(*this); // Make a copy of the matrix

	K det = 1;
	for (int i = 0; i < n; ++i) {
		// Find pivot
		K pivot = LU.get(i + 1, i + 1);
		if (pivot == 0) {
			// Try to pivot with a row below
			bool pivot_found = false;
			for (int j = i + 1; j < n; ++j) {
				if (LU.get(j + 1, i + 1) != 0) {
					LU.swap_line(i + 1, j + 1);
					pivot = LU.get(i + 1, i + 1);
					det = -det;
					pivot_found = true;
					break;
				}
			}
			if (!pivot_found) {
				return 0; // Matrix is singular
			}
		}

		// Lu decomposition process
		for (int j = i + 1; j < n; ++j) {
			K factor = LU.get(j + 1, i + 1) / pivot;
			for (int k = i + 1; k < n; ++k) {
				K val = LU.get(j + 1, k + 1) - factor * LU.get(i + 1, k + 1);
				LU.set(j + 1, k + 1, val);
			}
		}
		det *= pivot;
	}

	return det;
}

template <class K>
Matrix<K> Matrix<K>::inverse()
{
	if (this->is_square() == 0)
		throw std::invalid_argument("The matrix must be square");
	if (this->determinant() == 0)
		throw std::invalid_argument("The matrix must have a non null determinant.");

    unsigned n = line;  // Since the matrix is square, number of rows = number of columns
    Matrix<K> augmented(n, 2 * n);  // Create an augmented matrix [A | I]

    // Initialize the augmented matrix: [A | I]
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            augmented.set(i + 1, j + 1, this->get(i + 1, j + 1));  // Copy A into the left part
            augmented.set(i + 1, j + 1 + n, (i == j) ? 1 : 0);  // Set the identity matrix on the right
        }
    }

    // Perform Gaussian elimination
    for (unsigned i = 0; i < n; ++i) {
        // Find the pivot row
        unsigned pivot_row = i;
        for (unsigned j = i + 1; j < n; ++j) {
            if (augmented.get(j + 1, i + 1) > augmented.get(pivot_row + 1, i + 1)) {
                pivot_row = j;
            }
        }

        // Swap the current row with the pivot row
        if (pivot_row != i) {
            augmented.swap_line(i + 1, pivot_row + 1);
        }

        // Make the pivot element 1 by scaling the row
        K pivot = augmented.get(i + 1, i + 1);
        if (pivot == 0) {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }

        // Scale the row so the pivot becomes 1
        for (unsigned j = 0; j < 2 * n; ++j) {
            augmented.set(i + 1, j + 1, augmented.get(i + 1, j + 1) / pivot);
        }

        // Eliminate the other elements in the current column
        for (unsigned j = 0; j < n; ++j) {
            if (i != j) {
                K scale = augmented.get(j + 1, i + 1);
                for (unsigned k = 0; k < 2 * n; ++k) {
                    augmented.set(j + 1, k + 1, augmented.get(j + 1, k + 1) - scale * augmented.get(i + 1, k + 1));
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    Matrix<K> inverse(n, n);
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            inverse.set(i + 1, j + 1, augmented.get(i + 1, j + 1 + n));
        }
    }

    return inverse;
}

template<class K>
unsigned Matrix<K>::rank() {
    unsigned n = line;  // Number of rows
    unsigned m = column; // Number of columns

    Matrix<K> augmented(*this);  // Create a copy of the matrix for row reduction

    unsigned rank = 0;  // This will hold the rank of the matrix

    for (unsigned i = 0; i < n; ++i) {
        // Find the pivot column for the current row
        unsigned pivot_column = i;
        bool found_pivot = false;

        for (unsigned j = i; j < m; ++j) {
            if (augmented.get(i + 1, j + 1) != 0) {
                pivot_column = j;
                found_pivot = true;
                break;
            }
        }

        // If no pivot is found, this row is a zero row and can be ignored
        if (!found_pivot) {
            continue;
        }

        // Swap the current row with the row that contains the pivot
        if (pivot_column != i) {
            augmented.swap_line(i + 1, pivot_column + 1);
        }

        // Scale the pivot row to make the pivot element 1
        K pivot = augmented.get(i + 1, i + 1);
        for (unsigned j = 0; j < m; ++j) {
            augmented.set(i + 1, j + 1, augmented.get(i + 1, j + 1) / pivot);
        }

        // Eliminate the current column in all rows below the pivot
        for (unsigned j = i + 1; j < n; ++j) {
            K scale = augmented.get(j + 1, i + 1);
            for (unsigned k = 0; k < m; ++k) {
                augmented.set(j + 1, k + 1, augmented.get(j + 1, k + 1) - scale * augmented.get(i + 1, k + 1));
            }
        }

        // Increment the rank, as we have found a non-zero row
        ++rank;
    }

    return rank;
}

template<class K>
unsigned Matrix<K>::get_line() const {
    return this->line;
}

template<class K>
unsigned Matrix<K>::get_column() const {
    return this->column;
}

template<class K>
bool Matrix<K>::is_square() const {
    if (this->line == this->column)
        return true;
    return false;
}

template<class K>
bool Matrix<K>::is_vector() const {
    return this->vector;
}

template<class K>
bool Matrix<K>::is_nonzero(unsigned line_find) const {
    for (int column_find = 1; column_find <= this->column; ++column_find) {
        if (this->get(line_find, column_find) == 0) {
            return false;
        }
    }
    return true;
}

template<class K>
bool Matrix<K>::is_identity() const {
	for (int current_diagonal = 1; current_diagonal <= this->line; ++current_diagonal) {
		if (this->get(current_diagonal, current_diagonal) != 1) {
			return false;
		}
	}
	return true;
}


template<class K>
void Matrix<K>::print() {
    std::cout << *this;
}

template<class K>
void Matrix<K>::matrix_to_vector() {
    K **data_vector = new K*[this->line];

    for (int line_copy = 0; line_copy < this->line; ++line_copy) {
        data_vector[line_copy] = new K[1];
        data_vector[line_copy][0] = this->data[line_copy][0];
    }

    for (int line_delete = 0; line_delete < this->line; ++line_delete) {
        delete [] data[line_delete];
    }

    delete [] data;

    this->column = 1;
    this->vector = true;
    this->data = data_vector;
}

template<class K>
void Matrix<K>::vector_to_matrix() {
    this->vector = false;
}

template<class K>
Matrix<K> Matrix<K>::operator+(Matrix<K> const &matrix) {
    Matrix<K> result(*this);
    result.add(matrix);
    return result;
}

template<class K>
Matrix<K> Matrix<K>::operator-(Matrix<K> const &matrix) {
    Matrix<K> result(*this);
    result.subtract(matrix);
    return result;
}

template<class K>
Matrix<K> Matrix<K>::operator*(Matrix<K> const &matrix) {
    Matrix<K> result(*this);
    return result.multiply(matrix);
}

template<class K>
Matrix<K> Matrix<K>::operator*(K scale) {
    Matrix<K> result(*this);
    result.scale(scale);
    return result;
}

template <class K>
Matrix<K> add(Matrix<K> matrix_a, Matrix<K> matrix_b) {
    Matrix<K> result(matrix_a);
    result.add(matrix_b);
    return result;
}

template <class K>
Matrix<K> subtract(Matrix<K> matrix_a, Matrix<K> matrix_b) {
    Matrix<K> result(matrix_a);
    result.subtract(matrix_b);
    return result;
}

template <class K>
class Vector : public Matrix<K> {
    public:
        Vector();
        explicit Vector(Matrix<K> matrix);
        explicit Vector(unsigned line);
        Vector(unsigned line, const std::initializer_list<K> &value);
        Vector(Vector &copy);
        Vector(Vector &&copy) noexcept;

        Vector& operator=(const Vector &copy);
        Vector& operator=(Vector &&copy) noexcept ;

        ~Vector() override = default;

        K dotProduct(Vector<K> &vector);
        float norm_1();
        float norm();
        float norm_inf();

        Vector<K> operator+(Vector<K> const &vector);
        Vector<K> operator-(Vector<K> const &vector);
        Vector<K> operator*(Vector<K> const &vector);
        Vector<K> operator*(K scale);
};

template<class K>
std::ostream &operator<<(std::ostream &output, Vector<K> &input) {
    output << "is a square : " << input.is_square() << std::endl;
    output << "is a vector : " << input.is_vector() << std::endl;
    for (int line_print = 0; line_print < input.get_line(); ++line_print) {
        output << "[";
        for (int column_print = 0; column_print < input.get_column(); ++column_print) {
            if (column_print < input.get_column() - 1) {
                output << std::setw(10) << (input.get(line_print + 1, column_print + 1)) << ", ";
            } else {
                output << std::setw(10) << (input.get(line_print + 1, column_print + 1));
            }
        }
        output << "]" << std::endl;
    }
    if (input.get_line() == 0) {
        output << "empty matrix" << std::endl;
    }
    output << std::endl;
    return output;
}

template<class K>
Vector<K>::Vector() : Matrix<K>(){
    this->vector = true;
}

template<class K>
Vector<K>::Vector(Matrix<K> matrix) {
    if (matrix.get_column() > 0) {
        this->line = matrix.get_line();
        this->column = 1;
        this->vector = true;
        this->data = new K*[this->line];

        for (int line_set = 0; line_set < this->line; ++line_set) {
            this->data[line_set] = new K[1];
            this->data[line_set][0] = matrix.get(line_set + 1, 1);
        }
    } else {
        this->line = 0;
        this->column = 0;
        this->vector = false;
        this->data = nullptr;
    }
}

template<class K>
Vector<K>::Vector(unsigned int line) {
    this->line = line;
    this->column = 1;
    this->vector = true;
    this->data = new K*[line];

    for (int line_set = 0; line_set < line; ++line_set) {
        this->data[line_set] = new K[1];
        this->data[line_set][0] = 0;
    }
}

template<class K>
Vector<K>::Vector(unsigned int line, const std::initializer_list<K> &value) {
    this->line = line;
    this->column = 1;
    this->vector = true;
    this->data = new K*[line];

    auto value_iterator = value.begin();

    for (int line_set = 0; line_set < line; ++line_set) {
        this->data[line_set] = new K[1];
        if (value_iterator != value.end()) {
            this->data[line_set][0] = *(value_iterator++);
        } else {
            this->data[line_set][0] = K();
        }
    }
}

template<class K>
Vector<K>::Vector(Vector &copy) : Matrix<K>(copy) {
    this->vector = true;
}

template<class K>
Vector<K>::Vector(Vector &&copy) noexcept : Matrix<K>(copy) {
    this->vector = true;
}

template<class K>
Vector<K> &Vector<K>::operator=(const Vector &copy) {
    if (this != &copy) {
        this->line = copy.line;
        this->column = 1;
        this->vector = true;
        this->data = new K *[copy.line];

        for (int line_copy = 0; line_copy < copy.line; ++line_copy) {
            this->data[line_copy] = new K[copy.column];
            this->data[line_copy][0] = copy.data[line_copy][0];
        }
    }
    return *this;
}

template<class K>
Vector<K> &Vector<K>::operator=(Vector &&copy) noexcept {
    if (this != &copy) {
        this->line = copy.line;
        this->column = 1;
        this->vector = true;
        this->data = copy.data;

        copy.line = 0;
        copy.column = 0;
        copy.vector = false;
        copy.data = nullptr;
    }
    return *this;
}

template<class K>
K Vector<K>::dotProduct(Vector<K>& vector) {
    if (vector.line != this->line) {
        std::cout << "incompatible vector" << std::endl;
        std::cout << vector;
        std::cout << "and" << std::endl;
        std::cout << *this;
        return K();
    }

    K result = 0;
    for (int cursor = 0; cursor < this->line; ++cursor) {
        result = std::fma(this->data[cursor][0], vector.data[cursor][0], result);
    }

    return result;
}

template<class K>
float Vector<K>::norm_1() {
    float result = 0.0f;

    for (int line_norm = 0; line_norm < this->line; line_norm++) {
        if (this->data[line_norm][0] < 0) {
            result -= this->data[line_norm][0];
        } else {
            result += this->data[line_norm][0];
        }
    }

    return result;
}

template<class K>
float Vector<K>::norm() {
    float result = 0.0f;

    for (int line_norm = 0; line_norm < this->line; line_norm++) {
        result = std::fma(this->data[line_norm][0], this->data[line_norm][0], result);
    }

    result = std::pow(result, 0.5f);

    return result;
}

template<class K>
float Vector<K>::norm_inf() {
    float result = 0.0f;

    for (int line_norm = 0; line_norm < this->line; line_norm++) {
        if (this->data[line_norm][0] < 0) {
            result = std::max(static_cast<float>(-this->data[line_norm][0]), result);
        } else {
            result = std::max(static_cast<float>(this->data[line_norm][0]), result);
        }
    }

    return result;
}

template<class K>
Vector<K> Vector<K>::operator+(Vector<K> const &vector) {
    Vector<K> result(*this);
    result.add(vector);
    return result;
}

template<class K>
Vector<K> Vector<K>::operator-(Vector<K> const &vector) {
    Vector<K> result(*this);
    result.subtract(vector);
    return result;
}

template<class K>
Vector<K> Vector<K>::operator*(Vector<K> const &vector) {
    Vector<K> result(*this);
    result.multiply(vector);
    return result;
}

template<class K>
Vector<K> Vector<K>::operator*(K scale) {
    Vector<K> result(*this);
    result.scale(scale);
    return result;
}


template <class K>
[[nodiscard]] Vector<K> add(Vector<K> vector_a, Vector<K> vector_b) {
    Vector<K> result(vector_a);
    result.add(vector_b);
    return result;
}

template <class K>
[[nodiscard]] Vector<K> subtract(Vector<K> vector_a, Vector<K> vector_b) {
    Vector<K> result(vector_a);
    result.subtract(vector_b);
    return result;
}

template<class K>
[[nodiscard]] Vector<K> linear_combination(const std::initializer_list<Vector<K>> &vector_list, const std::initializer_list<K> &scale) {
    auto scale_iterator = scale.begin();
    auto vector_iterator = vector_list.begin();

    Vector<K> result(vector_iterator->get_line());
    K result_buffer = K();

    unsigned old = vector_iterator->get_line();

    if (vector_list.size() != scale.size())
        return Vector<K>(0);

    for (int scale_cursor = 0; scale_cursor < scale.size(); scale_cursor++) {
        if ((vector_iterator + scale_cursor)->get_line() != old) {
            std::cout << "incompatible vector" << std::endl;
            return Vector<K>(0);
        }
    }

    for (int scale_cursor = 0; scale_cursor < vector_iterator->get_line(); scale_cursor++) {
        for (int vector_cursor = 0; vector_cursor < scale.size(); vector_cursor++) {
            result_buffer = std::fma((vector_iterator + vector_cursor)->get(scale_cursor + 1, 1), *(scale_iterator + vector_cursor), result_buffer);
        }
        result.set(scale_cursor + 1, 1, result_buffer);
        result_buffer = K();
    }
    return result;
}

template<class V>
[[nodiscard]] V lerp(V variable_one, V variable_two, float slider) {
    if (slider >= 0.0f && slider <= 1.0f)
        return variable_one * (1 - slider) + variable_two * (slider);
    throw std::invalid_argument("invalid slider range");
}

template<class K>
[[nodiscard]] float angle_cos(Vector<K> u, Vector<K> v) {
    if (u.get_line() == v.get_line())
        return u.dotProduct(v) / (u.norm() * v.norm());
    return 0;
}

template<class K>
[[nodiscard]] Vector<K> cross_product(Vector<K> u, Vector<K> v) {
    if (u.get_line() == 3 && v.get_line() == 3) {
        Vector<K> result(3);

        result.set(1, 1, std::fma(-u.get(3, 1), v.get(2, 1), u.get(2, 1) * v.get(3, 1)));
        result.set(2, 1, std::fma(-u.get(1, 1), v.get(3, 1), u.get(3, 1) * v.get(1, 1)));
        result.set(3, 1, std::fma(-u.get(2, 1), v.get(1, 1), u.get(1, 1) * v.get(2, 1)));

        return result;
    }
    return Vector<float>();
}

#endif //MATRIX_MATRIX_TPP