#include <Matrix.tpp>

auto main() -> int
{
	Matrix<float> matrix_a(4, 3, {8., 5., -2., 4., 7., 20., 7., 6., 1., 21., 18., 7.});

	std::cout << matrix_a.rank() << std::endl;
}