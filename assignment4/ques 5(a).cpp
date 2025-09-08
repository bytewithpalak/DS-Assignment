#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << "\n";  // 20
    cout << s.pop() << "\n";  // 20
    cout << s.pop() << "\n";  // 10
    cout << s.pop() << "\n";  // -1 (empty)
    return 0;
}
