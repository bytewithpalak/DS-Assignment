#include <iostream>
using namespace std;

class Queue {
    int queue[5];
    int front, rear;
    int size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue full\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        queue[rear] = x;
        cout << x << " added\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        cout << queue[front] << " removed\n";
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue empty\n";
        } else {
            cout << "Front element: " << queue[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, val;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.IsEmpty 4.IsFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            if (q.isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
        } else if (choice == 4) {
            if (q.isFull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
        } else if (choice == 5) {
            q.display();
        } else if (choice == 6) {
            q.peek();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
