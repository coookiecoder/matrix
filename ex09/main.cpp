#include <Matrix.tpp>

auto main() -> int {
    Matrix<int> matrix_a(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    std::cout << matrix_a << std::endl;
    std::cout << matrix_a.transpose() << std::endl;

    Matrix<int> matrix_b(2, 2, {1, 2, 3, 4});

    std::cout << matrix_b << std::endl;
    std::cout << matrix_b.transpose() << std::endl;

    Matrix<int> matrix_c(2, 3, {1, 2, 3, 4, 5, 6});

    std::cout << matrix_c << std::endl;
    std::cout << matrix_c.transpose() << std::endl;
}