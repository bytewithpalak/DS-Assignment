#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertBefore(int key, int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == key) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Node " << key << " not found." << endl;
        } else {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Node " << key << " not found." << endl;
        } else {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Node " << key << " not found." << endl;
        } else {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found." << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, key;

    do {
        cout << endl << "--- Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a Node" << endl;
        cout << "4. Insert After a Node" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete a Specific Node" << endl;
        cout << "8. Search for a Node" << endl;
        cout << "9. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key (node value): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertBefore(key, value);
            break;
        case 4:
            cout << "Enter key (node value): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAfter(key, value);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;
        case 9:
            list.display();
            break;
        case 0:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
