#include <iostream>
#include <string>
using namespace std;

// ----------------- Book Class -----------------
class Book {
private:
    string id;
    string name;
    double price;
    string author;
    string isbn;

public:
    Book() { id = name = author = isbn = ""; price = 0.0; }

    Book(string i, string n, double p, string a, string is) {
        id = i; name = n; price = p; author = a; isbn = is;
    }

    // Getters
    string getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    string getAuthor() { return author; }
    string getISBN() { return isbn; }

    // Setters
    void setName(string n) { name = n; }
    void setPrice(double p) { price = p; }
    void setAuthor(string a) { author = a; }
    void setISBN(string is) { isbn = is; }

    void printBook() {
        cout << "ID: " << id << ", Name: " << name 
             << ", Price: $" << price 
             << ", Author: " << author 
             << ", ISBN: " << isbn << endl;
    }
};

// ----------------- Node Class -----------------
class Node {
private:
    Book b;
    Node* next;
    Node* prev;

public:
    Node() { next = prev = nullptr; }
    Node(Book book) { b = book; next = prev = nullptr; }

    Book getBook() { return b; }
    Node* getNext() { return next; }
    Node* getPrev() { return prev; }

    void setBook(Book book) { b = book; }
    void setNext(Node* n) { next = n; }
    void setPrev(Node* p) { prev = p; }

    friend class BookList;
};

// ----------------- BookList Class -----------------
class BookList {
private:
    Node* head;

public:
    BookList() { head = nullptr; }

    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* n = new Node(b);

        if (head == nullptr) {
            head = n;
            head->setNext(head);
            head->setPrev(head);
            cout << "Book added successfully!" << endl;
            return;
        }

        Node* last = head->getPrev();
        last->setNext(n);
        n->setPrev(last);
        n->setNext(head);
        head->setPrev(n);
        cout << "Book added successfully!" << endl;
    }

    void removeBook(string id) {
        if (head == nullptr) {
            cout << "No book to remove!" << endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->getBook().getId() == id) {
                if (temp->getNext() == temp) { // Only one book
                    delete temp;
                    head = nullptr;
                    cout << "Book removed successfully!" << endl;
                    return;
                }
                Node* prevNode = temp->getPrev();
                Node* nextNode = temp->getNext();
                prevNode->setNext(nextNode);
                nextNode->setPrev(prevNode);
                if (temp == head) head = nextNode;
                delete temp;
                cout << "Book removed successfully!" << endl;
                return;
            }
            temp = temp->getNext();
        } while (temp != head);

        cout << "Book ID not found!" << endl;
    }

    void updateBook(string id, string name, double price, string author, string isbn) {
        if (head == nullptr) {
            cout << "No book to update!" << endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->getBook().getId() == id) {
                temp->getBook().setName(name);
                temp->getBook().setPrice(price);
                temp->getBook().setAuthor(author);
                temp->getBook().setISBN(isbn);
                cout << "Book updated successfully!" << endl;
                return;
            }
            temp = temp->getNext();
        } while (temp != head);

        cout << "Book ID not found!" << endl;
    }

    void printBooks() {
        if (head == nullptr) {
            cout << "No books in the list!" << endl;
            return;
        }

        Node* temp = head;
        cout << "\n--- Book List ---\n";
        do {
            temp->getBook().printBook();
            temp = temp->getNext();
        } while (temp != head);
    }

    void printBook(string id) {
        if (head == nullptr) {
            cout << "No book found!" << endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->getBook().getId() == id) {
                cout << "\n--- Book Details ---\n";
                temp->getBook().printBook();
                return;
            }
            temp = temp->getNext();
        } while (temp != head);

        cout << "Book ID not found!" << endl;
    }
};

// ----------------- Main Function -----------------
int main() {
    BookList bl;
    int choice;
    string id, name, author, isbn;
    double price;

    do {
        cout << "\n--- Book Management ---\n";
        cout << "1. Add Book\n2. Remove Book\n3. Update Book\n4. Print All Books\n5. Print Single Book\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: "; cin >> id;
                cout << "Enter Book Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Book Price: "; cin >> price;
                cout << "Enter Book Author: "; cin.ignore(); getline(cin, author);
                cout << "Enter Book ISBN: "; getline(cin, isbn);
                bl.addBook(id, name, price, author, isbn);
                break;

            case 2:
                cout << "Enter Book ID to remove: "; cin >> id;
                bl.removeBook(id);
                break;

            case 3:
                cout << "Enter Book ID to update: "; cin >> id;
                cout << "Enter New Book Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter New Book Price: "; cin >> price;
                cout << "Enter New Book Author: "; cin.ignore(); getline(cin, author);
                cout << "Enter New Book ISBN: "; getline(cin, isbn);
                bl.updateBook(id, name, price, author, isbn);
                break;

            case 4:
                bl.printBooks();
                break;

            case 5:
                cout << "Enter Book ID to print: "; cin >> id;
                bl.printBook(id);
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
