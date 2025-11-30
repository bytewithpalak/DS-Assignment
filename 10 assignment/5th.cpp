#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node* nxt;
    Node(int x) { v = x; nxt = NULL; }
};

int main() {
    int n;
    cin >> n;

    vector<Node*> arr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(new Node(x));
    }

   
    for(int i = 0; i < n - 1; i++)
        arr[i]->nxt = arr[i+1];

    int lp;
    cin >> lp;      

    if(lp != -1)
        arr[n-1]->nxt = arr[lp];

    Node* h = arr[0];

    unordered_set<Node*> s;
    while(h) {
        if(s.count(h)) {
            cout << "true";
            return 0;
        }
        s.insert(h);
        h = h->nxt;
    }

    cout << "false";
    return 0;
}
