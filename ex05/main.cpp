#include <Matrix.tpp>

auto main() -> int {
    Vector<float> vector_a(2, {1, 0});
    Vector<float> vector_b(2, {1, 0});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {1, 0});
    vector_b = Vector<float>(2, {0, 1});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {-1, 1});
    vector_b = Vector<float>(2, {1, -1});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(2, {2, 1});
    vector_b = Vector<float>(2, {4, 2});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3, {1, 2, 3});
    vector_b = Vector<float>(3, {4, 5, 6});

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3);
    vector_b = Vector<float>(3);

    std::cout << angle_cos(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(4);
    vector_b = Vector<float>(3);

    std::cout << angle_cos(vector_a, vector_b) << std::endl;
}