#include <Matrix.tpp>

auto main() -> int {
    Matrix<float> matrix_a(3, 5, {8, 5, -2, 4, 28, 4, 2.5f, 20, 4, -4, 8, 5, 1, 4, 17});

    std::cout << matrix_a << std::endl;
    std::cout << matrix_a.row_echelon();
}