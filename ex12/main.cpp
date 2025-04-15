#include <Matrix.tpp>

auto main() -> int {
	Matrix<float> matrix_a(3, 3, {
		1., 0., 0.,
		0., 1., 0.,
		0., 0., 1.});

	std::cout << matrix_a.inverse() << std::endl;

	Matrix<float> matrix_b(3, 3, {
		2., 0., 0.,
		0., 2., 0.,
		0., 0., 2.});

	std::cout << matrix_b.inverse() << std::endl;

	Matrix<float> matrix_c(3, 3, {
		8., 5., -2.,
		4., 7., 20.,
		7., 6., 1.});

	std::cout << matrix_c.inverse() << std::endl;
}