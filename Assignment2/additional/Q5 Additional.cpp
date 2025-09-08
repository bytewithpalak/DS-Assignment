#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            for(int j = n-1; j > i; j--) {
                arr[j] = arr[j-1];
            }
            if(i+1 < n) arr[i+1] = 0;
            i++; 
        }
    }

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
