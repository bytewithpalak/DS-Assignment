#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int,int> m;

    for(int x : a) m[x]++;

    for(int x : a) {
        if(m[x] == 1) {
            cout << x;
            return 0;
        }
    }

    cout << "-1";
    return 0;
}
