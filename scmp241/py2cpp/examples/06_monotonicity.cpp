#include <iostream>
#include <vector>
#include <ranges>

bool is_strictly_increasing(const std::vector<int>& sequence)
{
    for (auto i : std::views::iota(1u, sequence.size())) {
        if (sequence.at(i) <= sequence.at(i-1)) {
            return false;
        }
    }
    return true;
}

int main()
{
    const std::vector primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    std::cout << "Prime sequence is ";
    if (!is_strictly_increasing(primes)) std::cout << "not ";
    std::cout << "strictly increasing.\n";

    const std::vector fibonacci = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    std::cout << "Fibonacci sequence is ";
    if (!is_strictly_increasing(fibonacci)) std::cout << "not ";
    std::cout << "strictly increasing.\n";
}