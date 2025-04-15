#include <Matrix.tpp>

auto main() -> int
{
	Matrix<float> matrix_a(4, 3, {8., 5., -2., 4., 7., 20., 7., 6., 1., 21., 18., 7.});

	std::cout << matrix_a.rank() << std::endl;

	Matrix<float> matrix_c(3, 4, {1, 2, 0, 0, 2, 4, 0, 0, -1, 2, 1, 1});

	std::cout << matrix_c.rank() << std::endl;

	Matrix<float> matrix_b(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});

	std::cout << matrix_b.rank() << std::endl;
}