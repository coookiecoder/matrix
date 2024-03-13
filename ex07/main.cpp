#include <Matrix.tpp>

auto main() -> int {
    Matrix<int> matrix_a(2, 2, {3, -5, 6, 8});
    Matrix<int> matrix_b(2, 2, {2, 1, 4, 2});

    std::cout << matrix_a.multiply(matrix_b);
}