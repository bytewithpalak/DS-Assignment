#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool possible = false;

    for(int i = 1; i < n-1; i++) {
        string a = s.substr(0, i);
        for(int j = i+1; j < n; j++) {
            string b = s.substr(i, j-i);
            string c = s.substr(j);
            if((a.find(b) != string::npos) || (b.find(a) != string::npos) ||
               (a.find(c) != string::npos) || (c.find(a) != string::npos) ||
               (b.find(c) != string::npos) || (c.find(b) != string::npos)) {
                possible = true;
                break;
            }
        }
        if(possible) break;
    }
    cout << (possible ? "YES" : "NO");
    return 0;
}
