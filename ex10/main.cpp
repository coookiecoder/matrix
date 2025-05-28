#include <Matrix.tpp>

auto main() -> int {
	Matrix<float> matrix(2, 2, {0, 0, 0, 0});
	std::cout << matrix.row_echelon() << std::endl;

	matrix = Matrix<float>(2, 2, {1, 0, 0, 1});
	std::cout << matrix.row_echelon() << std::endl;

	matrix = Matrix<float>(2, 2, {4, 2, 2, 1});
	std::cout << matrix.row_echelon() << std::endl;

	matrix = Matrix<float>(2, 2, {-7, 2, 4, 8});
	std::cout << matrix.row_echelon() << std::endl;

	matrix = Matrix<float>(2, 2, {1, 2, 4, 8});
	std::cout << matrix.row_echelon() << std::endl;

	return 0;
}
