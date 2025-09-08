#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    int total = n*(n+1)/2;
    int sum = 0;
    for(int i=0; i<n-1; i++) sum += arr[i];
    return total - sum;
}

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n-2; 
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] != mid+1) high = mid - 1;
        else low = mid + 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1,2,3,5,6};
    cout << "Linear: " << findMissingLinear(arr,6) << endl;
    cout << "Binary: " << findMissingBinary(arr,6);
    return 0;
}
