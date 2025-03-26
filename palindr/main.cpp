#include "palindrome.h"
#include <iostream>
#include <limits>

int main() {
    try {
        int64_t number;
        std::string filename;

        std::cout << "Enter a number to check if it's a palindrome: ";
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Invalid input. Please enter an integer.");
        }

        std::cout << "Enter the output filename: ";
        std::cin >> filename;
        if (filename.empty()) {
            throw std::invalid_argument("Filename cannot be empty.");
        }

        bool isPal = palindrome::isPalindrome(number, filename);
        std::cout << "Result written to " << filename << ": " 
                  << (isPal ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
