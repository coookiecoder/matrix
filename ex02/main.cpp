#include <Matrix.tpp>

auto main() -> int {
    std::cout << "float :" << std::endl;

    std::cout << lerp(21.0, 42.0, 0.3) << std::endl;
    std::cout << lerp(0.0, 100.0, 0.5) << std::endl;
    std::cout << lerp(0.0, 100.0, 0.25) << std::endl;
    std::cout << lerp(100.0, 0.0, 0.5) << std::endl;
    std::cout << lerp(100.0, 0.0, 0.25) << std::endl;

    std::cout << lerp(0.0, 0.0, 0.5) << std::endl;

    std::cout << "Vector<float> :" << std::endl;

    std::cout << lerp(Vector<float>(2, {2.0f, 1.0f}), Vector<float>(2, {4.0f, 2.0f}), 0.3);
    std::cout << lerp(Vector<float>(2), Vector<float>(2, {100.0f, 100.0f}), 0.5);
    std::cout << lerp(Vector<float>(2), Vector<float>(2, {100.0f, 100.0f}), 0.25);
    std::cout << lerp(Vector<float>(2, {100.0f, 100.0f}), Vector<float>(2), 0.5);
    std::cout << lerp(Vector<float>(2, {100.0f, 100.0f}), Vector<float>(2), 0.25);

    std::cout << lerp(Vector<float>(2), Vector<float>(2), 0.5);

    std::cout << "Matrix<float> :" << std::endl;

    std::cout << lerp(Matrix<float>(2, 2, {2.0f, 1.0f, 3.0f, 4.0f}), Matrix<float>(2, 2, {20.0f, 10.0f, 30.0f, 40.0f}), 0.5);
    std::cout << lerp(Matrix<float>(2, 2), Matrix<float>(2, 2, {100.0f, 100.0f, 100.0f, 100.0f}), 0.5);
    std::cout << lerp(Matrix<float>(2, 2), Matrix<float>(2, 2, {100.0f, 100.0f, 100.0f, 100.0f}), 0.25);
    std::cout << lerp(Matrix<float>(2, 2, {100.0f, 100.0f, 100.0f, 100.0f}), Matrix<float>(2, 2), 0.5);
    std::cout << lerp(Matrix<float>(2, 2, {100.0f, 100.0f, 100.0f, 100.0f}), Matrix<float>(2, 2), 0.25);

    std::cout << lerp(Matrix<float>(2, 2), Matrix<float>(2, 2), 0.5);

    try {
        std::cout << lerp(0.0, 0.0, 2.0);
    } catch (std::invalid_argument &error) {
        std::cerr << "error : " << error.what() << std::endl;
    }

    try {
        std::cout << lerp(0.0, 0.0, -2.0);
    } catch (std::invalid_argument &error) {
        std::cerr << "error : " << error.what() << std::endl;
    }
}
