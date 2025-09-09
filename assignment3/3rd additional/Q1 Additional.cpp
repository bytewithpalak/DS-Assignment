#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmaller(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = nearestSmaller(arr);
    for(int x : res) cout << x << " ";
    return 0;
}
