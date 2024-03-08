#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <iostream>
#include <iomanip>

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
        Matrix(Matrix &copy);
        Matrix(Matrix &&copy) noexcept;

        Matrix& operator=(const Matrix &copy);
        Matrix& operator=(Matrix &&copy) noexcept;

        ~Matrix();

        void set(unsigned line_set, unsigned column_set, K value);
        K get(unsigned line_set, unsigned column_set);

        void add(Matrix matrix);
        void subtract(Matrix matrix);
        virtual Matrix<K> multiply(Matrix matrix);
        void scale(K scale);

        unsigned get_line();
        unsigned get_column();

        bool is_square();
        bool is_vector();

        virtual void print();

        void matrix_to_vector();
        void vector_to_matrix();

        Matrix<K> operator+(Matrix<K>& matrix);
        Matrix<K> operator-(Matrix<K>& matrix);
        Matrix<K> operator*(Matrix<K>& matrix);
};

template<class K>
std::ostream &operator<<(std::ostream &output, Matrix<K> &input) {
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
    if (input.get_line() == 0 && input.get_column() == 0) {
        output << "empty matrix" << std::endl;
    }
    output << std::endl;
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
Matrix<K>::Matrix(Matrix &copy) : line(copy.line), column(copy.column), vector(copy.vector) {
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
    if (line_set <= this->line && column_set <= this->column) {
        this->data[line_set - 1][column_set - 1] = value;
    } else {
        std::cout << "error while setting the data at " << line_set << " " << column_set << std::endl;
    }
}

template<class K>
K Matrix<K>::get(unsigned line_set, unsigned column_set) {
    if (line_set <= this->line && column_set <= this->column) {
        return this->data[line_set - 1][column_set - 1];
    } else {
        std::cout << "error while getting the data at " << line_set << " " << column_set << std::endl;
        return K();
    }
}

template<class K>
void Matrix<K>::add(Matrix matrix) {
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
void Matrix<K>::subtract(Matrix matrix) {
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
Matrix<K> Matrix<K>::multiply(Matrix matrix) {
    if (this->line == matrix.column && this->column == matrix.line) {
        Matrix<K> result(this->line, matrix.column);

        for (int line_multiply= 0; line_multiply < result.line; ++line_multiply) {
            for (int column_multiply = 0; column_multiply < result.column; ++column_multiply) {
                K buffer;
                for (int cursor = 0; cursor < this->column; ++cursor) {
                    buffer += this->data[line_multiply][cursor] * matrix.data[cursor][column_multiply];
                }
                result.set(line_multiply, column_multiply, buffer);
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
unsigned Matrix<K>::get_line() {
    return this->line;
}

template<class K>
unsigned Matrix<K>::get_column() {
    return this->column;
}

template<class K>
bool Matrix<K>::is_square() {
    if (this->line == this->column)
        return true;
    return false;
}

template<class K>
bool Matrix<K>::is_vector() {
    return this->vector;
}

template<class K>
void Matrix<K>::print() {
    std::cout << *this;
}

template<class K>
void Matrix<K>::matrix_to_vector() {
    K **data_vector = new K[this->line];

    for (int line_copy = 0; line_copy < this->line; ++line_copy) {
        data_vector[line_copy] = new K[1];
        data_vector[line_copy][0] = this->data[line_copy][0];
    }

    for (int line_delete = 0; line_delete < this->line; ++line_delete) {
        delete [] data[line_delete];
    }

    delete [] data;

    this->data = data_vector;
}

template<class K>
void Matrix<K>::vector_to_matrix() {
    this->vector = false;
}

template<class K>
Matrix<K> Matrix<K>::operator+(Matrix<K> &matrix) {
    Matrix<K> result(*this);
    result.add(matrix);
    return result;
}

template<class K>
Matrix<K> Matrix<K>::operator-(Matrix<K> &matrix) {
    Matrix<K> result(*this);
    result.subtract(matrix);
    return result;
}

template<class K>
Matrix<K> Matrix<K>::operator*(Matrix<K> &matrix) {
    Matrix<K> result(*this);
    result.multiply(matrix);
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

        ~Vector() = default;

        K dotProduct(Vector<K> &vector);

        virtual void print();

        Vector<K> operator+(Vector<K>& vector);
        Vector<K> operator-(Vector<K>& vector);
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
    if (matrix.column > 0) {
        this->line = matrix.line;
        this->column = 1;
        this->vector = true;
        this->data = new K*[this->line];

        for (int line_set = 0; line_set < this->line; ++line_set) {
            this->data[line_set] = new K[1];
            this->data[line_set][0] = matrix.data[line_set][0];
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
            this->data[copy.line] = new K[copy.column];
            this ->data[line_copy][0] = copy.data[line_copy][0];
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
        result += this->data[cursor][0] * vector.data[cursor][0];
    }

    return result;
}

template<class K>
void Vector<K>::print() {
    std::cout << *this;
}

template<class K>
Vector<K> Vector<K>::operator+(Vector<K> &vector) {
    Vector<K> result(*this);
    result.add(vector);
    return result;
}

template<class K>
Vector<K> Vector<K>::operator-(Vector<K> &vector) {
    Vector<K> result(*this);
    result.subtract(vector);
    return result;
}

#endif //MATRIX_MATRIX_HPP