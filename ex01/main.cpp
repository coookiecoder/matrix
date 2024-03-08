#include <Matrix.tpp>

auto main() -> int {
    Vector<int> vector_test_a(3, {1, 2, 3});
    Vector<int> vector_test_b(3, {0, 10, -100});

    Vector<int> result;

    result = linear_combination({vector_test_a, vector_test_b}, {10, -2});

    std::cout << result;

    Vector<int> vector_a(5, {1, 2, 3, 4, 5});
    Vector<int> vector_b(5, {1, 2, 3, 4, 5});
    Vector<int> vector_c(5, {1, 2, 3, 4, 5});
    Vector<int> vector_d(5, {1, 2, 3, 4, 5});
    Vector<int> vector_e(5, {1, 2, 3, 4, 5});

    result = linear_combination({vector_a, vector_b, vector_c, vector_d, vector_e}, {10, 10, 10, 10, 10});

    std::cout << result;

    vector_a.scale(10);
    vector_b.scale(10);
    vector_c.scale(10);
    vector_d.scale(10);
    vector_e.scale(10);

    result = vector_a;
    result.add(vector_b);
    result.add(vector_c);
    result.add(vector_d);
    result.add(vector_e);

    std::cout << result;

    Vector<int> vector_error_a(3, {1, 2, 3});
    Vector<int> vector_error_b(4, {0, 10, -100});

    result = linear_combination({vector_error_a, vector_error_b}, {10, -2});

    std::cout << result;
}