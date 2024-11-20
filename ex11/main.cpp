#include <Matrix.tpp>

auto main() -> int {
	Matrix<float> matrix_a(2, 2, {
		1., -1,
		-1, 1.});

	std::cout << matrix_a.determinant() << std::endl;

	Matrix<float> matrix_b(3, 3, {
		2, 0, 0,
		0, 2, 0,
		0, 0, 2});

	std::cout << matrix_b.determinant() << std::endl;

	Matrix<float> matrix_c(3, 3, {
		8, 5, -2,
		4, 7, 20,
		7, 6, 1});

	std::cout << matrix_c.determinant() << std::endl;

	Matrix<float> matrix_d(4, 4, {
		8,   5,  -2, 4,
		4,   25, 20, 4,
		8,   5,  1,  4,
		28, -4,  17, 1});

	std::cout << matrix_d.determinant() << std::endl;

	Matrix<float> matrix_e(10, 10, {
		2, 3, 1, 5, 7, 9, 1, 5, 2, 6,
		1, 8, 4, 9, 2, 6, 3, 9, 7, 5,
		3, 5, 6, 1, 8, 2, 4, 6, 8, 2,
		5, 7, 1, 3, 4, 6, 7, 2, 5, 1,
		6, 8, 9, 4, 3, 1, 5, 7, 4, 8,
		2, 1, 3, 2, 6, 5, 8, 3, 7, 9,
		7, 2, 4, 6, 5, 8, 9, 1, 3, 6,
		8, 5, 7, 9, 1, 3, 6, 4, 2, 5,
		4, 6, 5, 8, 2, 7, 1, 9, 6, 3,
		9, 4, 2, 7, 6, 1, 5, 2, 8, 4});

	std::cout << std::setprecision(128) << matrix_e.determinant() << std::endl;
}
