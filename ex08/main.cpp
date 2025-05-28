#include <Matrix.tpp>

auto main() -> int {
    Matrix<float> matrix_a(2, 2, {0, 0, 0, 0});
    std::cout << matrix_a.trace() << std::endl;

    matrix_a = Matrix<float>(2, 2, {1, 0, 0, 1});
    std::cout << matrix_a.trace() << std::endl;

    matrix_a = Matrix<float>(2, 2, {1, 2, 3, 4});
    std::cout << matrix_a.trace() << std::endl;

    matrix_a = Matrix<float>(2, 2, {8, -7, 4, 2});
    std::cout << matrix_a.trace() << std::endl;

    matrix_a = Matrix<float>(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
    std::cout << matrix_a.trace() << std::endl;
}