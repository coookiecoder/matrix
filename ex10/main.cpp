#include <Matrix.tpp>

auto main() -> int {
	Matrix<float> matrix_a(3, 5, {8, 5, -2, 4, 28, 4, 2.5f, 20, 4, -4, 8, 5, 1, 4, 17});
	std::cout << matrix_a.row_echelon() << std::endl;

	Matrix<float> matrix_b(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
	std::cout << matrix_b.row_echelon() << std::endl;

	Matrix<float> matrix_c(2, 2, {1, 2, 3, 4});
	std::cout << matrix_c.row_echelon() << std::endl;

	Matrix<float> matrix_d(2, 2, {1, 2, 2, 4});
	std::cout << matrix_d.row_echelon() << std::endl;
}