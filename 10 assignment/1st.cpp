#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_set<int> s;

    for(int x : a) {
        if(s.count(x)) {
            cout << "true";
            return 0;
        }
        s.insert(x);
    }

    cout << "false";
    return 0;
}
