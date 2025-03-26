#pragma once

#include <vector>
#include <stdexcept>
#include <cstdint>
#include <string>

namespace fibonacci {
std::vector<uint64_t> getFirstNFibonacciNumbers(size_t n, const std::string& filename);
}
