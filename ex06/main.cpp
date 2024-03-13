#include <Matrix.tpp>

auto main() -> int {
    Vector<float> vector_a(3, {1, 2, 3});
    Vector<float> vector_b(3, {4, 5, 6});

    std::cout << cross_product(vector_a, vector_b);

    vector_a = Vector<float>(3, {4, 2, -3});
    vector_b = Vector<float>(3, {-2, -5, 16});

    std::cout << cross_product(vector_a, vector_b);

    vector_a = Vector<float>(4, {4, 2, -3});
    vector_b = Vector<float>(3, {-2, -5, 16});

    std::cout << cross_product(vector_a, vector_b);
}