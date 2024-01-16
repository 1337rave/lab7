if (count > 0) {
    return count;
}
else {
    return -1; // Element not found
}
    }

    void Reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList<int> intList;

    int choice;
    int value;
    int position;

    do {
        std::cout << "Menu:\n"
            << "1. Add to Head\n"
            << "2. Add to Tail\n"
            << "3. Delete from Head\n"
            << "4. Delete from Tail\n"
            << "5. Delete All\n"
            << "6. Show\n"
            << "7. Insert at Position\n"
            << "8. Delete at Position\n"
            << "9. Search\n"
            << "10. Replace\n"
            << "11. Reverse\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            intList.AddToHead(value);
            std::cout << "Added to Head.\n";
            break;

        case 2:
            std::cout << "Enter value: ";
            std::cin >> value;
            intList.AddToTail(value);
            std::cout << "Added to Tail.\n";
            break;

        case 3:
            intList.DeleteFromHead();
            std::cout << "Deleted from Head.\n";
            break;

        case 4:
            intList.DeleteFromTail();
            std::cout << "Deleted from Tail.\n";
            break;

        case 5:
            intList.DeleteAll();
            std::cout << "All elements deleted.\n";
            break;

        case 6:
            intList.Show();
            break;

        case 7:
            std::cout << "Enter value: ";
            std::cin >> value;
            std::cout << "Enter position: ";
            std::cin >> position;
            intList.InsertAtPosition(value, position);
            std::cout << "Inserted at Position.\n";
            break;

        case 8:
            std::cout << "Enter position: ";
            std::cin >> position;
            intList.DeleteAtPosition(position);
            std::cout << "Deleted at Position.\n";
            break;

        case 9:
            std::cout << "Enter value to search: ";
            std::cin >> value;
            position = intList.Search(value);
            if (position != -1) {
                std::cout << "Value found at position: " << position << "\n";
            }
            else {
                std::cout << "Value not found.\n";
            }
            break;

        case 10:
            std::cout << "Enter value to replace: ";
            std::cin >> value;
            std::cout << "Enter new value: ";
            int newValue;
            std::cin >> newValue;
            int count = intList.Replace(value, newValue);
            if (count != -1) {
                std::cout << "Replaced " << count << " occurrences.\n";
            }
            else {
                std::cout << "Value not found.\n";
            }
            break;

        case 11:
            intList.Reverse();
            std::cout << "List reversed.\n";
            break;

        case 0:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

