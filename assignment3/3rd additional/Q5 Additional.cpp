#include<bits/stdc++.h>
using namespace std;

bool canSort(vector<int> &arr) {
    vector<int> B;
    stack<int> S;
    int n = arr.size();
    int need = 1;

    for(int i = 0; i < n; i++) {
        S.push(arr[i]);
        while(!S.empty() && S.top() == need) {
            B.push_back(S.top());
            S.pop();
            need++;
        }
    }
    return (need == n+1);
}

int main() {
    vector<int> arr = {4, 1, 2, 3};
    if(canSort(arr)) cout << "Possible\n";
    else cout << "Not Possible\n";
    return 0;
}
