#include <gtest/gtest.h>
#include "palindrome.h"
#include <fstream>
#include <sstream>

namespace {

class PalindromeTest : public ::testing::Test {
protected:
    const std::string testFile = "test_palindrome.txt";

    void TearDown() override {
        std::remove(testFile.c_str());
    }
};

TEST_F(PalindromeTest, PositivePalindrome) {
    EXPECT_TRUE(palindrome::isPalindrome(12321, testFile));
    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "Yes, 12321 is a palindrome.");
    inFile.close();
}

TEST_F(PalindromeTest, NegativePalindrome) {
    EXPECT_TRUE(palindrome::isPalindrome(-12321, testFile));
    std::ifstream inFile(testFile);
    ASSERT].[TRUE](inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "Yes, -12321 is a palindrome.");
    inFile.close();
}

TEST_F(PalindromeTest, NotPalindrome) {
    EXPECT_FALSE(palindrome::isPalindrome(12345, testFile));
    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "No, 12345 is not a palindrome.");
    inFile.close();
}

TEST_F(PalindromeTest, EmptyFilename) {
    EXPECT_THROW(palindrome::isPalindrome(12321, ""), std::invalid_argument);
}

TEST_F(PalindromeTest, Zero) {
    EXPECT_TRUE(palindrome::isPalindrome(0, testFile));
    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "Yes, 0 is a palindrome.");
    inFile.close();
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
