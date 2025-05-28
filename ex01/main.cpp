#include <Matrix.tpp>

auto main() -> int {
    std::cout << linear_combination({Vector<float>(2, {-42, 42})}, {-1.0f}) << std::endl;

    std::cout << linear_combination({Vector<float>(1, {-42}), Vector<float>(1, {-42}), Vector<float>(1, {-42})}, {-1.0f, 1.0f, 0.0f}) << std::endl;

    std::cout << linear_combination({Vector<float>(2, {-42, 42}), Vector<float>(2, {1, 3}), Vector<float>(2, {10, 20})}, {1.0f, -10.0f, -1.0f}) << std::endl;

    std::cout << linear_combination({Vector<float>(3, {-42, 100, -69.5}), Vector<float>(3, {1, 3, 5})}, {1.0f, -10.0f}) << std::endl;
}