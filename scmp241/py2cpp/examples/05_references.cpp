#include <iostream>

void my_func_by_value(int a)
{
    a *= 2;
}

void my_func_by_reference(int& a)
{
    a *= 2;
}

int main()
{
    int a = 5;
    std::cout << "a is " << a << "\n";

    int& b = a;
    std::cout << "b is " << b << "\n";

    std::cout << "Now doing: b += 3\n";
    b += 3;

    std::cout << "a is " << a << "\n";
    std::cout << "b is " << b << "\n";

    std::cout << "calling my_func_by_value(a)\n";
    my_func_by_value(a);
    std::cout << "a is " << a << "\n";
    std::cout << "calling my_func_by_reference(a)\n";
    my_func_by_reference(a);
    std::cout << "a is " << a << "\n";
}