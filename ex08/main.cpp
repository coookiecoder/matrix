#include <Matrix.tpp>

auto main() -> int {
    Matrix<int> matrix_a(3, 3, {2, -5, 0, 4, 3, 7, -2, 3, 4});

    std::cout << matrix_a.trace() << std::endl;

    matrix_a = Matrix<int>(3, 3, {-2, -8, 4, 1, -23, 4, 0, 6, 4});

    std::cout << matrix_a.trace() << std::endl;

    matrix_a = Matrix<int>(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});

    std::cout << matrix_a.trace() << std::endl;
}