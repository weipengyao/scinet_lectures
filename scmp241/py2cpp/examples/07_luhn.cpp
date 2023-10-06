#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>

bool check_luhn(const std::vector<int>& number)
{
    int sum = 0;
    auto view = number | std::views::reverse | std::views::drop(1);
    for (int i = 0; auto digit : view) {
        if (i % 2 == 0)
            digit *= 2;
        if (digit > 9)
            digit -= 9;
        sum += digit;
        i++;
    }
    const int check_digit_calculated = (10 - (sum % 10)) % 10;
    const int check_digit = number.back();
    return check_digit_calculated == check_digit;
}

std::vector<int> read_digits(const std::string& prompt = "Please enter the number:")
{
    std::cout << prompt << " ";
    std::string input_string;
    std::cin >> input_string;
    std::vector<int> output;
    std::ranges::transform(input_string, std::back_inserter(output), [](const char c){ return c - 0x30; });
    return output;
}

int main()
{
    /*** Please do not save your real credit card information in this source file. ***/
    // You may instead read it from standard input like so:
    //   std::vector number = read_digits();
    // In this case, the secret number only exists in RAM, which is relatively safe.
    const std::vector number = {2, 4, 4, 5, 3, 9, 4, 2, 5, 8, 8, 1, 1, 3, 6, 9};

    if (check_luhn(number))
        std::cout << "Validation succeeded.\n";
    else
        std::cout << "Validation failed.\n";
}