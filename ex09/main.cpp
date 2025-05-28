#include <Matrix.tpp>

auto main() -> int {
    Matrix<float> matrix(2, 2, {0, 0, 0, 0});
    std::cout << matrix << std::endl;
    std::cout << matrix.transpose() << std::endl;

    matrix = Matrix<float>(2, 2, {1, 0, 0, 1});
    std::cout << matrix << std::endl;
    std::cout << matrix.transpose() << std::endl;

    matrix = Matrix<float>(2, 2, {1, 2, 3, 4});
    std::cout << matrix << std::endl;
    std::cout << matrix.transpose() << std::endl;

    matrix = Matrix<float>(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
    std::cout << matrix << std::endl;
    std::cout << matrix.transpose() << std::endl;

    matrix = Matrix<float>(3, 2, {1, 2, 3, 4, 5, 6});
    std::cout << matrix << std::endl;
    std::cout << matrix.transpose() << std::endl;

    return 0;
}
