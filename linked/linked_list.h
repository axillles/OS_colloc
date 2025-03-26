#pragma once

#include <string>
#include <stdexcept>

namespace linked_list {
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* reverseList(Node* head, const std::string& filename);

    Node* createListFromInput();
    void deleteList(Node* head);
}
