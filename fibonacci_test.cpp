#include <gtest/gtest.h>
#include "fibonacci.h"
#include <fstream>
#include <sstream>

namespace {

class FibonacciTest : public ::testing::Test {
protected:
    const std::string testFile = "test_fibonacci.txt";

    void TearDown() override {
        std::remove(testFile.c_str());
    }
};

TEST_F(FibonacciTest, SingleElement) {
    auto result = fibonacci::getFirstNFibonacciNumbers(1, testFile);
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 0);

    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    uint64_t value;
    inFile >> value;
    EXPECT_EQ(value, 0);
    inFile.close();
}

TEST_F(FibonacciTest, FiveElements) {
    auto result = fibonacci::getFirstNFibonacciNumbers(5, testFile);
    std::vector<uint64_t> expected = {0, 1, 1, 2, 3};
    ASSERT_EQ(result.size(), 5);
    EXPECT_EQ(result, expected);

    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "0 1 1 2 3");
    inFile.close();
}

TEST_F(FibonacciTest, ZeroInput) {
    EXPECT_THROW(fibonacci::getFirstNFibonacciNumbers(0, testFile), std::invalid_argument);
}

TEST_F(FibonacciTest, EmptyFilename) {
    EXPECT_THROW(fibonacci::getFirstNFibonacciNumbers(5, ""), std::invalid_argument);
}

TEST_F(FibonacciTest, Overflow) {
    EXPECT_THROW(fibonacci::getFirstNFibonacciNumbers(94, testFile), std::overflow_error);
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
