#include "palindrome.h"
#include <fstream>
#include <iostream>
#include <algorithm>

#define LOG_ERROR(msg) std::cerr << "ERROR: " << msg << std::endl

namespace palindrome {
    bool isPalindrome(int64_t number, const std::string& filename) {
        if (filename.empty()) {
            LOG_ERROR("Filename cannot be empty.");
            throw std::invalid_argument("Filename must not be empty.");
        }

        std::string numStr = std::to_string(number);
        std::string reversed = numStr;
        std::reverse(reversed.begin(), reversed.end());

        bool result = (numStr == reversed);

        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            LOG_ERROR("Failed to open file: " + filename);
            throw std::runtime_error("Unable to open output file.");
        }
        outFile << (result ? "Yes, " : "No, ") << number << (result ? " is a palindrome." : " is not a palindrome.");
        outFile.close();

        return result;
    }
}
