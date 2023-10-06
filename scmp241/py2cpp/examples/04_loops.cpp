#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector my_vector {35, 71, 85, 64, 77, 94,  0, 81, 74, 86};

    std::cout << "C-style for loop\n";
    for (unsigned i = 0; i < my_vector.size(); i++) {
        std::cout << i << ": " << my_vector.at(i) << "\n";
    }

    std::cout << "\nAn alternative to C-style loops\n";
    for (const auto i : std::views::iota(0u, my_vector.size())) {
        std::cout << i << ": " << my_vector.at(i) << "\n";
    }

    std::cout << "\nRange-based for loop\n";
    for (const auto& item : my_vector) {
        std::cout << item << "\n";
    }

    std::cout << "\nRange-based for loop with an init statement\n";
    for (int i = 0; const auto& item : my_vector) {
        std::cout << i << ": " << item << "\n";
        i++;
    }

    std::cout << "\nOften we use algorithms\n";
    std::ranges::for_each(my_vector, [](const auto& item){ std::cout << item << "\n"; });

    std::cout << "\n";
}