#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
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
