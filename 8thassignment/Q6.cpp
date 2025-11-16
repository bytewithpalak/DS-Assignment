#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;

            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap pq;

    pq.push(5);
    pq.push(20);
    pq.push(3);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl; 

    return 0;
}
