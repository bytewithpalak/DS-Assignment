#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main() {
    int arr[] = {64,34,25,12,22,11,90};
    bubbleSort(arr, 7);
    for(int i=0; i<7; i++) cout << arr[i] << " ";
    return 0;
}
