#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string concatStrings(string a, string b) {
    return a + b;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string removeVowels(string s) {
    string result = "";
    for(char c: s) {
        if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&
           c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U')
            result += c;
    }
    return result;
}

void sortStrings(vector<string> &v) {
    sort(v.begin(), v.end());
}

char toLowerCase(char c) {
    if(c>='A' && c<='Z') return c + 32;
    return c;
}

int main() {
    cout << concatStrings("Hello","World") << endl;
    cout << reverseString("Hello") << endl;
    cout << removeVowels("Beautiful") << endl;
    vector<string> w = {"apple","dog","cat","ball"};
    sortStrings(w);
    for(auto &x:w) cout << x << " ";
    cout << endl;
    cout << toLowerCase('A');
    return 0;
}
