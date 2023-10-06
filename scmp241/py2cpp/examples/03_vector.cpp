#include <iostream>
#include <vector>

int main()
{
    /* Different constructors of the vector class */
    std::vector<int> empty_vector; // Empty int vector.
    std::vector<int> vector_default_value(5); // Int vector of size 5 with default value.
    std::vector vector_custom_value(5, 999); // Vector of size 5 with custom value. the value type (int) is deduced!
    std::vector vector_initializer_list {1, 2, 3}; // Vector with the content {1, 2, 3}. Again no template argument.
    std::vector vector_copy_constructed {vector_default_value}; // This is a copy.

    // Access the size of the vector
    std::cout << "vector_default_value.size() = " << vector_default_value.size() << "\n";

    // Append an element
    vector_default_value.push_back(100);
    std::cout << "vector_default_value.size() = " << vector_default_value.size() << "\n";

    // To check if the vector is empty, we can compare its size to zero
    // or use the `empty` method.
    if (empty_vector.empty())
        std::cout << "empty_vector.empty() is true\n";

    // To access an element us the `at` method
    std::cout << "vector_custom_value.at(2) = " << vector_custom_value.at(2) << "\n";
    
    // Works the same when modifying an element
    vector_custom_value.at(2) = 777;
    std::cout << "vector_custom_value.at(2) = " << vector_custom_value.at(2) << "\n";
}