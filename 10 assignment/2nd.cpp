#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> a(n1), b(n2);
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];

    unordered_set<int> s(a.begin(), a.end());
    vector<int> r;

    for(int x : b)
        if(s.count(x)) r.push_back(x);

    for(int x : r) cout << x << " ";
    return 0;
}
