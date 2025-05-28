#include <Matrix.tpp>

auto main() -> int {
    Vector<float> vector_a(2, {0, 0});
    Vector<float> vector_b(2, {0, 0});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<float>(2, {1, 0});
    vector_b = Vector<float>(2, {0, 0});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<float>(2, {1, 0});
    vector_b = Vector<float>(2, {1, 0});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<float>(2, {1, 0});
    vector_b = Vector<float>(2, {0, 1});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<float>(2, {1, 1});
    vector_b = Vector<float>(2, {1, 1});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<float>(2, {4, 2});
    vector_b = Vector<float>(2, {2, 1});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;
}
