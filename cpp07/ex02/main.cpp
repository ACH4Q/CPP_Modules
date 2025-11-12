#include <iostream>
#include "Array.hpp"

template <typename T>
void printArray(const std::string& name, const Array<T>& arr) {
    std::cout << "Contents of " << name << " (size " << arr.size() << "): [ ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "--- Test 1: Default Constructor ---" << std::endl;
    Array<int> empty_array;
    printArray("empty_array", empty_array);
    std::cout << std::endl;

    std::cout << "--- Test 2: Constructor with Size ---" << std::endl;
    Array<int> numbers(5);
    printArray("numbers (initially)", numbers);

    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = (i + 1) * 10;
    }
    printArray("numbers (after filling)", numbers);
    std::cout << std::endl;
    
    std::cout << "--- Test 3: String Array ---" << std::endl;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "World";
    words[2] = "42";
    printArray("words", words);
    std::cout << std::endl;

    std::cout << "--- Test 4: Deep Copy ---" << std::endl;
    Array<int> copied_array(numbers);
    printArray("numbers", numbers);
    printArray("copied_array", copied_array);
    
    Array<int> assigned_array;
    assigned_array = numbers;
    printArray("assigned_array", assigned_array);

    std::cout << "\n-> Modifying original 'numbers' array[0] to 999..." << std::endl;
    numbers[0] = 999;

    printArray("numbers (modified)", numbers);
    printArray("copied_array (unchanged)", copied_array);
    printArray("assigned_array (unchanged)", assigned_array);
    std::cout << std::endl;

    std::cout << "--- Test 5: Out of Bounds Access ---" << std::endl;
    try {
        std::cout << "Attempting to access numbers[10]..." << std::endl;
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception as expected: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access numbers[-1]..." << std::endl;
        std::cout << numbers[-1] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception as expected: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "--- Test 6: Const Array ---" << std::endl;
    const Array<int> const_array = numbers;
    printArray("const_array", const_array);
    std::cout << "Read access to const_array[1]: " << const_array[1] << std::endl;

    return 0;
}