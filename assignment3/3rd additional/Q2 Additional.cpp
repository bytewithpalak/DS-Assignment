#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> s, minS;
public:
    void push(int x) {
        s.push(x);
        if(minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }
    void pop() {
        if(s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return minS.top();
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(2);
    st.push(8);
    cout << "Min: " << st.getMin() << endl; 
    st.pop();
    cout << "Min: " << st.getMin() << endl; 
    st.pop();
    cout << "Min: " << st.getMin() << endl; 
    return 0;
}
