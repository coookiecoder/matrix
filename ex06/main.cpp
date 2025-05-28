#include <Matrix.tpp>

auto main() -> int {
    Vector<float> vector_a(3, {0, 0, 0});
    Vector<float> vector_b(3, {0, 0, 0});
    std::cout << cross_product(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3, {1, 0, 0});
    vector_b = Vector<float>(3, {0, 0, 0});
    std::cout << cross_product(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3, {1, 0, 0});
    vector_b = Vector<float>(3, {0, 1, 0});
    std::cout << cross_product(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3, {8, 7, -4});
    vector_b = Vector<float>(3, {3, 2, 1});
    std::cout << cross_product(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3, {1, 1, 1});
    vector_b = Vector<float>(3, {0, 0, 0});
    std::cout << cross_product(vector_a, vector_b) << std::endl;

    vector_a = Vector<float>(3, {1, 1, 1});
    vector_b = Vector<float>(3, {1, 1, 1});
    std::cout << cross_product(vector_a, vector_b) << std::endl;

    return 0;
}
