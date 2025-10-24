#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

// Function to display all employees
void display(Node* head) {
    if (head == NULL) {
        cout << "No employee record found!" << endl;
        return;
    }

    Node* temp = head;
    cout << "\nEmployee List: ";
    do {
        cout << temp->name << "  ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Add employee (Insert at end)
void addEmployee(Node*& head, string empName) {
    Node* newNode = new Node();
    newNode->name = empName;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        cout << "Employee added successfully!" << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    cout << "Employee added successfully!" << endl;
}

// Delete an employee
void deleteEmployee(Node*& head, string empName) {
    if (head == NULL) {
        cout << "No record to delete!" << endl;
        return;
    }

    Node* temp = head;
    Node* ptr = NULL;

    // Only one employee
    if (head->next == head && head->name == empName) {
        delete head;
        head = NULL;
        cout << "Employee deleted successfully!" << endl;
        return;
    }

    // Delete first node
    if (head->name == empName) {
        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        cout << "Employee deleted successfully!" << endl;
        return;
    }

    // Delete middle or last
    do {
        ptr = temp;
        temp = temp->next;

        if (temp->name == empName) {
            ptr->next = temp->next;
            delete temp;
            cout << "Employee deleted successfully!" << endl;
            return;
        }

    } while (temp != head);

    cout << "Employee not found!" << endl;
}

// Search for employee
void searchEmployee(Node* head, string empName) {
    if (head == NULL) {
        cout << "No record found!" << endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->name == empName) {
            cout << "Employee found successfully!" << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Employee not found!" << endl;
}

// Update employee name
void updateEmployee(Node* head, string oldName, string newName) {
    if (head == NULL) {
        cout << "No record found!" << endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->name == oldName) {
            temp->name = newName;
            cout << "Employee name updated successfully!" << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Employee not found!" << endl;
}

int main() {
    Node* head = NULL;
    int choice;
    string name, newName;

    do {
        cout << "\n--- Employee Record Management ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee Name\n";
        cout << "5. Display All Employees\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter employee name to add: ";
                cin >> name;
                addEmployee(head, name);
                break;

            case 2:
                cout << "Enter employee name to delete: ";
                cin >> name;
                deleteEmployee(head, name);
                break;

            case 3:
                cout << "Enter employee name to search: ";
                cin >> name;
                searchEmployee(head, name);
                break;

            case 4:
                cout << "Enter current employee name: ";
                cin >> name;
                cout << "Enter new name: ";
                cin >> newName;
                updateEmployee(head, name, newName);
                break;

            case 5:
                display(head);
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
