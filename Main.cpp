#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        DeleteAll();
    }

    void AddToHead(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) {
                tail = nullptr;
            }
        }
    }

    void DeleteFromTail() {
        if (head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
    }

    void DeleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> intList;

    int choice;
    int value;

    do {
        std::cout << "Menu:\n"
            << "1. Add to Head\n"
            << "2. Add to Tail\n"
            << "3. Delete from Head\n"
            << "4. Delete from Tail\n"
            << "5. Delete All\n"
            << "6. Show\n"
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

        case 0:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
