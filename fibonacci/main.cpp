#include "fibonacci.h"
#include <iostream>
#include <limits>

int main() {
    try {
        size_t n;
        std::string filename;

        std::cout << "Enter the number of Fibonacci numbers to generate: ";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Invalid input for n. Please enter a positive integer.");
        }
     
        std::cout << "Enter the output filename: ";
        std::cin >> filename;
        if (filename.empty()) {
            throw std::invalid_argument("Filename cannot be empty.");
        }

        auto fibNumbers = fibonacci::getFirstNFibonacciNumbers(n, filename);

        std::cout << "Fibonacci numbers written to " << filename << ": ";
        for (const auto& num : fibNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
