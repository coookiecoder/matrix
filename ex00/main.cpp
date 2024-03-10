#include <Matrix.tpp>

auto main(int argc, char **argv) -> int {
    if (argc == 2 || argc == 4) {
        Vector<int> vector_result;

        std::cout << "Vector A && B, add" << std::endl << std::endl;

        Vector vector_a(5, {1, 2, 3, 4, 5});
        Vector vector_b(5, {1, 2, 3, 4, 5});

        vector_result = vector_a + vector_b;

        vector_result.print();

        vector_result = add(vector_a, vector_b);

        vector_result.print();

        vector_a.add(vector_b);

        vector_a.print();

        vector_b.add(vector_a);

        vector_b.print();

        std::cout << "Vector C && D, subtract" << std::endl << std::endl;

        Vector vector_c(5, {1, 2, 3, 4, 5});
        Vector vector_d(5, {1, 2, 3, 4, 5});

        vector_result = vector_c - vector_d;

        vector_result.print();

        vector_result = subtract(vector_c, vector_d);

        vector_result.print();

        vector_c.subtract(vector_d);

        vector_c.print();

        vector_d.subtract(vector_c);

        vector_d.print();

        std::cout << "Vector E, scale && dot product" << std::endl << std::endl;

        Vector vector_e(5, {1, 2, 3, 4, 5});

        vector_e.scale(3);

        vector_e.print();

        std::cout << vector_e.dotProduct(vector_e) << std::endl << std::endl;

        std::cout << "Vector F, error" << std::endl << std::endl;

        Vector vector_f(6, {1, 2, 3, 4, 5});

        vector_result = vector_e - vector_f;

        vector_result.print();

        vector_result = vector_e + vector_f;

        vector_result.print();

        vector_f = Vector<int>();

        vector_f.print();
    }

    if (argc == 3 || argc == 4) {
        std::cout << "Matrix time" << std::endl << std::endl;

        Matrix<int> matrix_result;

        std::cout << "Matrix A && B, add" << std::endl << std::endl;

        Matrix matrix_a(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});
        Matrix matrix_b(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

        matrix_result = matrix_a + matrix_b;

        matrix_result.print();

        matrix_result = add(matrix_a, matrix_b);

        matrix_result.print();

        std::cout << "Matrix C && D, subtract" << std::endl << std::endl;

        Matrix matrix_c(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});
        Matrix matrix_d(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

        matrix_result = matrix_c - matrix_d;

        matrix_result.print();

        matrix_result = subtract(matrix_c, matrix_d);

        matrix_result.print();

        std::cout << "Matrix E, scale" << std::endl << std::endl;

        Matrix matrix_e(5, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

        matrix_e.scale(3);

        matrix_e.print();

        std::cout << "Matrix F, error" << std::endl << std::endl;

        Matrix matrix_f(4, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

        matrix_result = matrix_e - matrix_f;

        matrix_result.print();

        matrix_result = matrix_e + matrix_f;

        matrix_result.print();

        matrix_f = Matrix<int>();

        matrix_f.print();
    }

    if (argc == 4) {
        std::cout << "Conversion time" << std::endl << std::endl;

        Matrix matrix_g(4, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

        std::cout << "Matrix G" << std::endl << std::endl;

        matrix_g.print();

        matrix_g.matrix_to_vector();

        matrix_g.print();

        matrix_g.vector_to_matrix();

        matrix_g.print();

        Vector vector_g(4, {1, 2, 3, 4});

        std::cout << "Vector G" << std::endl << std::endl;

        vector_g.print();

        vector_g.vector_to_matrix();

        vector_g.print();

        vector_g.matrix_to_vector();

        vector_g.print();

        std::cout << "Matrix && Vector H && I" << std::endl << std::endl;

        Vector vector_h(matrix_g);
        Matrix matrix_h(vector_g);

        vector_h.print();
        matrix_h.print();

        Vector<int> vector_i(10);
        Matrix<int> matrix_i(10, 10);

        vector_i.print();
        matrix_i.print();
    }
}
