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

    void InsertAtPosition(const T& value, int position) {
        if (position < 0) {
            std::cout << "Invalid position.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
            return;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (!current) {
            std::cout << "Invalid position.\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (!newNode->next) {
            tail = newNode;
        }
    }

    void DeleteAtPosition(int position) {
        if (position < 0 || !head) {
            std::cout << "Invalid position.\n";
            return;
        }

        if (position == 0) {
            DeleteFromHead();
            return;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current->next && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (!current->next) {
            std::cout << "Invalid position.\n";
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;

        if (!current->next) {
            tail = current;
        }
    }

    int Search(const T& value) {
        Node* current = head;
        int position = 0;

        while (current) {
            if (current->data == value) {
                return position;
            }

            current = current->next;
            position++;
        }

        return -1; // Element not found
    }

    int Replace(const T& oldValue, const T& newValue) {
        Node* current = head;
        int count = 0;

        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                count++;
            }

            current = current->next;
        }
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

