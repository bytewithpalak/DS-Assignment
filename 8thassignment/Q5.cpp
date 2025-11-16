#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
public:
    void heapify(vector<int>& a, int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;

        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

    void sortIncreasing(vector<int>& a) {
        int n = a.size();
        
        for (int i = n/2 - 1; i >= 0; i--)
            heapify(a, n, i);

        for (int i = n-1; i >= 0; i--) {
            swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }
};

int main() {
    vector<int> a = {5, 3, 8, 4, 1};

    HeapSort hs;
    hs.sortIncreasing(a);

    cout << "Sorted: ";
    for (int x : a) cout << x << " ";

    return 0;
}
