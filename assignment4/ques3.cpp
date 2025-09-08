#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter an even number\n";
        return 0;
    }

    int arr[100];  // assuming max size 100

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result[100];

    int first = 0;
    int second = n / 2;
    int index = 0;

    while (second < n && first < n / 2) {
        result[index++] = arr[first++];
        result[index++] = arr[second++];
    }

    cout << "Interleaved output: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
