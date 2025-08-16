#include <iostream>
using namespace std;

class ArrayOperations {
    int arr[100];   // maximum size
    int n;          // current size

public:
    ArrayOperations() {
        n = 0; // initially empty
    }

    // 1. CREATE
    void create() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // 2. DISPLAY
    void display() {
        if (n == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 3. INSERT
    void insertElement() {
        int pos, val;
        cout << "Enter position (1 to " << n + 1 << "): ";
        cin >> pos;
        if (pos < 1 || pos > n + 1) {
            cout << "Invalid position!\n";
            return;
        }
        cout << "Enter value to insert: ";
        cin >> val;

        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1]; // shift right
        }
        arr[pos - 1] = val;
        n++;
        cout << "Element inserted.\n";
    }

    // 4. DELETE
    void deleteElement() {
        int pos;
        cout << "Enter position (1 to " << n << "): ";
        cin >> pos;
        if (pos < 1 || pos > n) {
            cout << "Invalid position!\n";
            return;
        }

        cout << "Deleted element: " << arr[pos - 1] << endl;
        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1]; // shift left
        }
        n--;
    }

    // 5. LINEAR SEARCH
    void linearSearch() {
        int key;
        cout << "Enter element to search: ";
        cin >> key;

        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i + 1 << endl;
                return;
            }
        }
        cout << "Element not found!\n";
    }
};

int main() {
    ArrayOperations obj;
    int choice;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.insertElement(); break;
            case 4: obj.deleteElement(); break;
            case 5: obj.linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
