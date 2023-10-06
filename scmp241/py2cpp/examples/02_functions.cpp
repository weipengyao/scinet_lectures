#include <iostream>
#include <tuple>

int find_bigger_number(int number)
{
    return number + 1;
}

int find_bigger_number(int number, int another_number)
{
    return number + another_number;
}

void print_number(int number = 8)
{
    std::cout << "The number is " << number << "\n";
}

std::tuple<int,int> sort_two_numbers(int a, int b)
{
    if (a > b) return {b, a};
    return {a, b};
}

int main()
{
    int a = 5;
    int b = 15;
    std::cout << find_bigger_number(a) << "\n";
    std::cout << find_bigger_number(a, b) << "\n";

    print_number();
    print_number(100);

    auto [smaller, bigger] = sort_two_numbers(21, 18);
    std::cout << smaller << " " << bigger << "\n";
}
