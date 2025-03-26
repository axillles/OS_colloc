#include <gtest/gtest.h>
#include "linked_list.h"
#include <fstream>
#include <sstream>

namespace {

class LinkedListTest : public ::testing::Test {
protected:
    const std::string testFile = "test_list.txt";

    void TearDown() override {
        std::remove(testFile.c_str());
    }
};

TEST_F(LinkedListTest, EmptyList) {
    Node* head = nullptr;
    head = linked_list::reverseList(head, testFile);
    EXPECT_EQ(head, nullptr);

    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "");
    inFile.close();
}

TEST_F(LinkedListTest, SingleElement) {
    Node* head = new Node(1);
    head = linked_list::reverseList(head, testFile);
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next, nullptr);

    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "1");
    inFile.close();

    linked_list::deleteList(head);
}

TEST_F(LinkedListTest, MultipleElements) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = linked_list::reverseList(head, testFile);
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->data, 3);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 1);
    EXPECT_EQ(head->next->next->next, nullptr);

    std::ifstream inFile(testFile);
    ASSERT_TRUE(inFile.is_open());
    std::stringstream ss;
    ss << inFile.rdbuf();
    EXPECT_EQ(ss.str(), "3 -> 2 -> 1");
    inFile.close();

    linked_list::deleteList(head);
}

TEST_F(LinkedListTest, EmptyFilename) {
    Node* head = new Node(1);
    EXPECT_THROW(linked_list::reverseList(head, ""), std::invalid_argument);
    linked_list::deleteList(head);
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
