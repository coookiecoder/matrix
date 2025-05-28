#include <Matrix.tpp>

auto main() -> int {
    Vector<float> vector_a(2, {1, 0});
    Vector<float> vector_b(2, {0, 1});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {8, 7});
    vector_b = Vector<float>(2, {3, 2});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {1, 1});
    vector_b = Vector<float>(2, {1, 1});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {4, 2});
    vector_b = Vector<float>(2, {1, 1});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {-7, 3});
    vector_b = Vector<float>(2, {6, 4});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;
}