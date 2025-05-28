#include <Matrix.tpp>

auto main() -> int {
    {
        std::cout << "vector addition" << std::endl;

        Vector<float> vector_a(2, {0, 0});
        Vector<float> vector_b(2, {0, 0});

        std::cout << vector_a + vector_b << std::endl;

        vector_a = Vector<float>(2, {1, 0});
        vector_b = Vector<float>(2, {0, 1});

        std::cout << vector_a + vector_b << std::endl;

        vector_a = Vector<float>(2, {1, 1});
        vector_b = Vector<float>(2, {1, 1});

        std::cout << vector_a + vector_b << std::endl;

        vector_a = Vector<float>(2, {21, 21});
        vector_b = Vector<float>(2, {21, 21});

        std::cout << vector_a + vector_b << std::endl;

        vector_a = Vector<float>(2, {-21, 21});
        vector_b = Vector<float>(2, {21, -21});

        std::cout << vector_a + vector_b << std::endl;

        vector_a = Vector<float>(10, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        vector_b = Vector<float>(10, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

        std::cout << vector_a + vector_b << std::endl;
    }

    {
        std::cout << "matrix addition" << std::endl;

        Matrix<float> matrix_a(2, 2, {0, 0, 0, 0});
        Matrix<float> matrix_b(2, 2, {0, 0, 0, 0});

        std::cout << matrix_a + matrix_b << std::endl;

        matrix_a = Matrix<float>(2, 2, {0, 0, 0, 0});
        matrix_b = Matrix<float>(2, 2, {1, 0, 0, 1});

        std::cout << matrix_a + matrix_b << std::endl;

        matrix_a = Matrix<float>(2, 2, {1, 1, 1, 1});
        matrix_b = Matrix<float>(2, 2, {1, 1, 1, 1});

        std::cout << matrix_a + matrix_b << std::endl;

        matrix_a = Matrix<float>(2, 2, {21, 21, 21, 21});
        matrix_b = Matrix<float>(2, 2, {21, 21, 21, 21});

        std::cout << matrix_a + matrix_b << std::endl;
    }

    {
        std::cout << "vector substraction" << std::endl;

        Vector<float> vector_a(2, {0, 0});
        Vector<float> vector_b(2, {0, 0});

        std::cout << vector_a - vector_b << std::endl;

        vector_a = Vector<float>(2, {1, 0});
        vector_b = Vector<float>(2, {0, 1});

        std::cout << vector_a - vector_b << std::endl;

        vector_a = Vector<float>(2, {1, 1});
        vector_b = Vector<float>(2, {1, 1});

        std::cout << vector_a - vector_b << std::endl;

        vector_a = Vector<float>(2, {21, 21});
        vector_b = Vector<float>(2, {21, 21});

        std::cout << vector_a - vector_b << std::endl;

        vector_a = Vector<float>(2, {-21, 21});
        vector_b = Vector<float>(2, {21, -21});

        std::cout << vector_a - vector_b << std::endl;

        vector_a = Vector<float>(10, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        vector_b = Vector<float>(10, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

        std::cout << vector_a - vector_b << std::endl;
    }

    {
        std::cout << "matrix substraction" << std::endl;

        Matrix<float> matrix_a(2, 2, {0, 0, 0, 0});
        Matrix<float> matrix_b(2, 2, {0, 0, 0, 0});

        std::cout << matrix_a - matrix_b << std::endl;

        matrix_a = Matrix<float>(2, 2, {0, 0, 0, 0});
        matrix_b = Matrix<float>(2, 2, {1, 0, 0, 1});

        std::cout << matrix_a - matrix_b << std::endl;

        matrix_a = Matrix<float>(2, 2, {1, 1, 1, 1});
        matrix_b = Matrix<float>(2, 2, {1, 1, 1, 1});

        std::cout << matrix_a - matrix_b << std::endl;

        matrix_a = Matrix<float>(2, 2, {21, 21, 21, 21});
        matrix_b = Matrix<float>(2, 2, {21, 21, 21, 21});

        std::cout << matrix_a - matrix_b << std::endl;
    }

    {
        std::cout << "vector scale" << std::endl;

        Vector<float> vector_a(2, {0, 0});
        vector_a.scale(1);

        std::cout << vector_a << std::endl;

        vector_a = Vector<float>(2, {1, 0});
        vector_a.scale(1);

        std::cout << vector_a << std::endl;

        vector_a = Vector<float>(2, {1, 1});
        vector_a.scale(2);

        std::cout << vector_a << std::endl;

        vector_a = Vector<float>(2, {21, 21});
        vector_a.scale(2);

        std::cout << vector_a << std::endl;

        vector_a = Vector<float>(2, {42, 42});
        vector_a.scale(0.5);

        std::cout << vector_a << std::endl;
    }

    {
        std::cout << "matrix scale" << std::endl;

        Matrix<float> matrix_a(2, 2, {0, 0, 0, 0});
        matrix_a.scale(0);

        std::cout << matrix_a  << std::endl;

        matrix_a = Matrix<float>(2, 2, {1, 0, 0, 1});
        matrix_a.scale(1);

        std::cout << matrix_a  << std::endl;

        matrix_a = Matrix<float>(2, 2, {1, 1, 1, 1});
        matrix_a.scale(2);

        std::cout << matrix_a  << std::endl;

        matrix_a = Matrix<float>(2, 2, {21, 21, 21, 21});
        matrix_a.scale(0.5);

        std::cout << matrix_a  << std::endl;
    }
}