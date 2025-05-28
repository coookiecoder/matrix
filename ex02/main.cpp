#include <Matrix.tpp>

auto main() -> int {
    std::cout << lerp(0.0f, 1.0f, 0.0f) << std::endl;

    std::cout << lerp(0.0f, 1.0f, 1.0f) << std::endl;

    std::cout << lerp(0.0f, 42.0f, 0.5f) << std::endl;

    std::cout << lerp(-42.0f, 42.0f, 0.5f) << std::endl;

    std::cout << lerp(Vector<float>(2, {-42, 42}), Vector<float>(2, {42, -42}), 0.5f) << std::endl;
}
