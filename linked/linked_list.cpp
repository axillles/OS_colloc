#include "linked_list.h"
#include <fstream>
#include <iostream>
#include <limits>

#define LOG_ERROR(msg) std::cerr << "ERROR: " << msg << std::endl

namespace linked_list {
    Node* reverseList(Node* head, const std::string& filename) {
        if (filename.empty()) {
            LOG_ERROR("Filename cannot be empty.");
            throw std::invalid_argument("Filename must not be empty.");
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            LOG_ERROR("Failed to open file: " + filename);
            throw std::runtime_error("Unable to open output file.");
        }

        Node* temp = head;
        while (temp != nullptr) {
            outFile << temp->data;
            if (temp->next != nullptr) outFile << " -> ";
            temp = temp->next;
        }
        outFile.close();

        return head;
    }

    Node* createListFromInput() {
        Node* head = nullptr;
        Node* tail = nullptr;
        int value;

        std::cout << "Enter list elements (enter a non-integer to stop): ";
        while (std::cin >> value) {
            Node* newNode = new Node(value);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return head;
    }

    void deleteList(Node* head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}
