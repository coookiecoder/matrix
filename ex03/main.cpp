#include <Matrix.tpp>

auto main() -> int {
    Vector<int> vector_a(2, {0, 0});
    Vector<int> vector_b(2, {1, 1});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<int>(2, {1, 1});
    vector_b = Vector<int>(2, {1, 1});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<int>(2, {-1, 6});
    vector_b = Vector<int>(2, {3, 2});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;

    vector_a = Vector<int>(4, {1, 2, 3, 4});
    vector_b = Vector<int>(4, {1, 2, 3, 4});

    std::cout << vector_a.dotProduct(vector_b) << std::endl;
}
