#include <Matrix.tpp>

auto main() -> int {
    std::cout << "Taxicab norm int" << std::endl;

    Vector<int> vector_a(3, {0, 0, 0});
    std::cout << vector_a.norm_1() << std::endl;

    vector_a = Vector<int>(3, {1, 2, 3});
    std::cout << vector_a.norm_1() << std::endl;

    vector_a = Vector<int>(2, {-1, -2});
    std::cout << vector_a.norm_1() << std::endl;

    vector_a = Vector<int>(2, {-2, -2});
    std::cout << vector_a.norm_1() << std::endl;

    std::cout << "Taxicab norm float" << std::endl;

    Vector<float> vector_b(3, {0.0, 0.0, 0.0});
    std::cout << vector_b.norm_1() << std::endl;

    vector_b = Vector<float>(3, {1.0, 2.0, 3.0});
    std::cout << vector_b.norm_1() << std::endl;

    vector_b = Vector<float>(2, {-1.0, -2.0});
    std::cout << vector_b.norm_1() << std::endl;

    vector_b = Vector<float>(2, {-2.0, -2.0});
    std::cout << vector_b.norm_1() << std::endl;

    std::cout << "Euclidean norm int" << std::endl;

    Vector<int> vector_c(3, {0, 0, 0});
    std::cout << vector_c.norm() << std::endl;

    vector_c = Vector<int>(3, {1, 2, 3});
    std::cout << vector_c.norm() << std::endl;

    vector_c = Vector<int>(2, {-1, -2});
    std::cout << vector_c.norm() << std::endl;

    vector_c = Vector<int>(2, {-2, -2});
    std::cout << vector_c.norm() << std::endl;

    std::cout << "Euclidean norm float" << std::endl;

    Vector<float> vector_d(3, {0.0, 0.0, 0.0});
    std::cout << vector_d.norm() << std::endl;

    vector_d = Vector<float>(3, {1.0, 2.0, 3.0});
    std::cout << vector_d.norm() << std::endl;

    vector_d = Vector<float>(2, {-1.0, -2.0});
    std::cout << vector_d.norm() << std::endl;

    vector_d = Vector<float>(2, {-2.0, -2.0});
    std::cout << vector_d.norm() << std::endl;

    std::cout << "Supremum norm int" << std::endl;

    Vector<int> vector_e(3, {0, 0, 0});
    std::cout << vector_e.norm_inf() << std::endl;

    vector_e = Vector<int>(3, {1, 2, 3});
    std::cout << vector_e.norm_inf() << std::endl;

    vector_e = Vector<int>(2, {-1, -2});
    std::cout << vector_e.norm_inf() << std::endl;

    vector_e = Vector<int>(2, {-2, -2});
    std::cout << vector_e.norm_inf() << std::endl;

    std::cout << "Supremum norm float" << std::endl;

    Vector<float> vector_f(3, {0.0, 0.0, 0.0});
    std::cout << vector_f.norm_inf() << std::endl;

    vector_f = Vector<float>(3, {1.0, 2.0, 3.0});
    std::cout << vector_f.norm_inf() << std::endl;

    vector_f = Vector<float>(2, {-1.0, -2.0});
    std::cout << vector_f.norm_inf() << std::endl;

    vector_f = Vector<float>(2, {-2.0, -2.0});
    std::cout << vector_f.norm_inf() << std::endl;
}