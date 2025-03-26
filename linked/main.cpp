#include "linked_list.h"
#include <iostream>

int main() {
    try {
        std::string filename;

        std::cout << "Creating linked list...\n";
        Node* head = linked_list::createListFromInput();

        std::cout << "Enter the output filename: ";
        std::cin >> filename;
        if (filename.empty()) {
            linked_list::deleteList(head);
            throw std::invalid_argument("Filename cannot be empty.");
        }

        head = linked_list::reverseList(head, filename);

        std::cout << "Reversed list written to " << filename << std::endl;

        linked_list::deleteList(head);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
