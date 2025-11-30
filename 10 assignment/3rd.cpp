#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int,int> m;
    for(int x : a) m[x]++;

    for(auto &p : m)
        cout << p.first << " -> " << p.second << " times\n";

    return 0;
}
