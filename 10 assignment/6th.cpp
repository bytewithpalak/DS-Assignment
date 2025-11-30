#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node* l;
    Node* r;
    Node(int x) { v = x; l = r = NULL; }
};

bool dfs(Node* r, unordered_set<int> &s) {
    if(!r) return false;
    if(s.count(r->v)) return true;
    s.insert(r->v);

    return dfs(r->l, s) || dfs(r->r, s);
}

int main() {
   
    
    int n;
    cin >> n;

    vector<Node*> a(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == -1) a[i] = NULL;
        else a[i] = new Node(x);
    }

    for(int i = 0; i < n; i++) {
        if(a[i]) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) a[i]->l = a[l];
            if(r < n) a[i]->r = a[r];
        }
    }

    unordered_set<int> s;

    if(dfs(a[0], s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
