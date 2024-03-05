#include <Matrix.tpp>

auto main() -> int {
    Vector<int> vector_result;

    Vector<int> vector_a(5, {1, 2, 3, 4, 5});
    Vector<int> vector_b(5, {1, 2, 3, 4, 5});

    vector_result = vector_a + vector_b;

    vector_result.print();

    Vector<int> vector_c(5, {1, 2, 3, 4, 5});
    Vector<int> vector_d(5, {1, 2, 3, 4, 5});

    vector_result = vector_c - vector_d;

    vector_result.print();

    Vector<int> vector_e(5, {1, 2, 3, 4, 5});

    vector_e.scale(3);
    vector_e.print();

    // matrix time

    Matrix<int> matrix_result;

    Matrix<int> matrix_a(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});
    Matrix<int> matrix_b(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

    matrix_result = matrix_a + matrix_b;

    matrix_result.print();

    Matrix<int> matrix_c(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});
    Matrix<int> matrix_d(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

    matrix_result = matrix_c - matrix_d;

    matrix_result.print();

    Matrix<int> matrix_e(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

    matrix_e.scale(3);
    matrix_e.print();
}
