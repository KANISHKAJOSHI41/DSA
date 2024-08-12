#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    char data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Add a node at the beginning
    void addAtBeg(char x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    // Append a node at the end
    void append(char x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add a node at a specific position
    void addAtPos(char x, int pos) {
        if (pos <= 0) {
            cout << "Invalid position. Cannot add." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = x;

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Invalid position. Cannot add." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Get the length of the linked list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp) {
            ++length;
            temp = temp->next;
        }
        return length;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display more information (address, value, and next address)
    void displayMore() {
        Node* temp = head;
        while (temp) {
            cout << "Address: " << temp << ", Value: " << temp->data;
            if (temp->next) {
                cout << ", Next Address: " << temp->next;
            }
            cout << endl;
            temp = temp->next;
        }
    }

    // Remove the first node
    void removeFirst() {
        if (!head) {
            cout << "List is empty. Cannot remove." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove the last node
    void removeLast() {
        if (!head) {
            cout << "List is empty. Cannot remove." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Remove a node at a specific position
    void removePos(int pos) {
        if (pos <= 0) {
            cout << "Invalid position. Cannot remove." << endl;
            return;
        }
        if (pos == 1) {
            removeFirst();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (!temp || !temp->next) {
            cout << "Invalid position. Cannot remove." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
};

int main() {
    LinkedList myList;
    myList.addAtBeg('A');
    myList.append('B');
    myList.addAtPos('C', 2);

    cout << "Length: " << myList.getLength() << endl;
    myList.display();
    myList.displayMore();

    myList.removeFirst();
    myList.removeLast();
    myList.removePos(1);

    myList.display();

    return 0;
}
