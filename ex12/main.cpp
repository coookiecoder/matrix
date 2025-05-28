#include <Matrix.tpp>

auto main() -> int {
	Matrix<float> matrix(2, 2, {1, 0, 0, 1});
	std::cout << matrix.inverse() << std::endl;

	matrix = Matrix<float>(2, 2, {2, 0, 0, 2});
	std::cout << matrix.inverse() << std::endl;

	matrix = Matrix<float>(2, 2, {0.5f, 0, 0, 0.5f});
	std::cout << matrix.inverse() << std::endl;

	matrix = Matrix<float>(2, 2, {0, 1, 1, 0});
	std::cout << matrix.inverse() << std::endl;

	matrix = Matrix<float>(2, 2, {1, 2, 3, 4});
	std::cout << matrix.inverse() << std::endl;

	matrix = Matrix<float>(3, 3, {1., 0., 0., 0., 1., 0., 0., 0., 1.});
	std::cout << matrix.inverse() << std::endl;

	return 0;
}