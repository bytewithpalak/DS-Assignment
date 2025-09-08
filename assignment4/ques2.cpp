#include <iostream>
using namespace std;

class CircularQueue {
    int queue[5];
    int front, rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue full\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
            queue[rear] = x;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = x;
        }
        cout << x << " added\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        cout << queue[front] << " removed\n";
        if (front == rear) {
            // Queue had one element, now empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
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
        int i = front;
        cout << "Queue elements: ";
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.IsEmpty 4.IsFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            if (q.isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
        }
        else if (choice == 4) {
            if (q.isFull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
        }
        else if (choice == 5) {
            q.display();
        }
        else if (choice == 6) {
            q.peek();
        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
