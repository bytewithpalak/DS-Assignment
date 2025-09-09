#include<bits/stdc++.h>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex) {
    int minIdx = -1;
    int minVal = INT16_MAX;
    int n = q.size();
    for(int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if(curr <= minVal && i <= sortedIndex) {
            minVal = curr;
            minIdx = i;
        }
        q.push(curr);
    }
    return minIdx;
}

void insertMinToRear(queue<int> &q, int minIndex) {
    int minVal;
    int n = q.size();
    for(int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if(i == minIndex) minVal = curr;
        else q.push(curr);
    }
    q.push(minVal);
}

void sortQueue(queue<int> &q) {
    for(int i = 1; i <= q.size(); i++) {
        int minIdx = minIndex(q, q.size() - i);
        insertMinToRear(q, minIdx);
    }
}

int main() {
    queue<int> q;
    q.push(11); q.push(5); q.push(4); q.push(21);

    sortQueue(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
