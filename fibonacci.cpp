#include "fibonacci.h"
#include <fstream>
#include <limits>
#include <iostream>

#define LOG_ERROR(msg) std::cerr << "ERROR: " << msg << std::endl

namespace fibonacci {
    std::vector<uint64_t> getFirstNFibonacciNumbers(size_t n, const std::string& filename) {
        if (n == 0) {
            LOG_ERROR("Input n must be positive.");
            throw std::invalid_argument("Number of Fibonacci elements must be greater than 0.");
        }
        if (filename.empty()) {
            LOG_ERROR("Filename cannot be empty.");
            throw std::invalid_argument("Filename must not be empty.");
        }

        std::vector<uint64_t> result;
        result.reserve(n);

        if (n >= 1) result.push_back(0);
        if (n >= 2) result.push_back(1);

        for (size_t i = 2; i < n; ++i) {
            uint64_t next = result[i - 1] + result[i - 2];
            if (next < result[i - 1]) {
                LOG_ERROR("Overflow occurred at index " + std::to_string(i));
                throw std::overflow_error("Fibonacci number exceeds uint64_t limit.");
            }
            result.push_back(next);
        }

        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            LOG_ERROR("Failed to open file: " + filename);
            throw std::runtime_error("Unable to open output file.");
        }

        for (size_t i = 0; i < result.size(); ++i) {
            outFile << result[i];
            if (i < result.size() - 1) outFile << " ";
        }
        outFile.close();

        return result;
    }
}
