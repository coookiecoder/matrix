#include <Matrix.tpp>

auto main() -> int {
    Matrix<float> matrix_a(2, 2, {0, 0, 0, 0});
    Vector<float> vector_a(2, {3, 5});
    std::cout << matrix_a.multiply(vector_a) << std::endl;

    matrix_a = Matrix<float>(2, 2, {1, 0, 0, 1});
    vector_a = Vector<float>(2, {7, -4});
    std::cout << matrix_a.multiply(vector_a) << std::endl;

    matrix_a = Matrix<float>(2, 2, {1, 1, 1, 1});
    vector_a = Vector<float>(2, {4, 2});
    std::cout << matrix_a.multiply(vector_a) << std::endl;

    matrix_a = Matrix<float>(2, 2, {2, 0, 0, 2});
    vector_a = Vector<float>(2, {2, 1});
    std::cout << matrix_a.multiply(vector_a) << std::endl;

    matrix_a = Matrix<float>(2, 2, {0.5, 0, 0, 0.5});
    vector_a = Vector<float>(2, {4, 2});
    std::cout << matrix_a.multiply(vector_a) << std::endl;

    return 0;
}
