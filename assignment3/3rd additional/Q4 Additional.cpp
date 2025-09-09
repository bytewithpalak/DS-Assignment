#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temp);
    for(int x : res) cout << x << " ";
    return 0;
}
