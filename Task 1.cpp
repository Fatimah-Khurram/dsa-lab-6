// fatima
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Insert node at beginning
void insertBefore(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert node at end
void insertAfter(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete a node by value
void deleteNode(Node*& head, int val) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    Node* ptr = NULL;

    // Case 1: Only one node
    if (head->next == head && head->data == val) {
        delete head;
        head = NULL;
        return;
    }

    // Case 2: Delete head node
    if (head->data == val) {
        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return;
    }

    // Case 3: Delete middle or last node
    do {
        ptr = temp;
        temp = temp->next;

        if (temp->data == val) {
            ptr->next = temp->next;
            delete temp;
            return;
        }
    } while (temp != head);

    cout << "Value not found!" << endl;
}

int main() {
    Node* head = NULL;
    int ch, val;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete a Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBefore(head, val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAfter(head, val);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(head, val);
                break;

            case 4:
                display(head);
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (ch != 5);

    return 0;
}

