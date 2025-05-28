#include <Matrix.tpp>

auto main() -> int {
    {
        std::cout << "Euclidean norm float" << std::endl;

        Vector<float> vector_a(1, {0});
        std::cout << vector_a.norm() << std::endl;

        vector_a = Vector<float>(1, {1});
        std::cout << vector_a.norm() << std::endl;

        vector_a = Vector<float>(2, {0, 0});
        std::cout << vector_a.norm() << std::endl;

        vector_a = Vector<float>(2, {1, 0});
        std::cout << vector_a.norm() << std::endl;

        vector_a = Vector<float>(2, {2, 1});
        std::cout << vector_a.norm() << std::endl;

        vector_a = Vector<float>(2, {4, 2});
        std::cout << vector_a.norm() << std::endl;

        vector_a = Vector<float>(2, {-4, -2});
        std::cout << vector_a.norm() << std::endl;
    }

    {
        std::cout << "Taxicab norm float" << std::endl;

        Vector<float> vector_a(1, {0});
        std::cout << vector_a.norm_1() << std::endl;

        vector_a = Vector<float>(1, {1});
        std::cout << vector_a.norm_1() << std::endl;

        vector_a = Vector<float>(2, {0, 0});
        std::cout << vector_a.norm_1() << std::endl;

        vector_a = Vector<float>(2, {1, 0});
        std::cout << vector_a.norm_1() << std::endl;

        vector_a = Vector<float>(2, {2, 1});
        std::cout << vector_a.norm_1() << std::endl;

        vector_a = Vector<float>(2, {4, 2});
        std::cout << vector_a.norm_1() << std::endl;

        vector_a = Vector<float>(2, {-4, -2});
        std::cout << vector_a.norm_1() << std::endl;
    }

    {
        std::cout << "Supremum norm float" << std::endl;

        Vector<float> vector_a(3, {0, 0, 0});
        std::cout << vector_a.norm_inf() << std::endl;

        vector_a = Vector<float>(3, {1, 2, 3});
        std::cout << vector_a.norm_inf() << std::endl;

        vector_a = Vector<float>(2, {-1, -2});
        std::cout << vector_a.norm_inf() << std::endl;

        vector_a = Vector<float>(2, {-2, -2});
        std::cout << vector_a.norm_inf() << std::endl;
    }
}