#include <bits/stdc++.h>
using namespace std;

int tenToTwo(int decimal) {
    stack<int> s;
    int res = 0;
    while (decimal != 0) {
        s.push(decimal % 2);
        decimal /= 2;
    }
    while (!s.empty()) {
        res = res * 10 + s.top();
        s.pop();
    }
    return res;
}

int main() {
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    stack<string> s;
    while (ss >> str) {
        s.push(str);
    }
    while (!s.empty()) {
        cout << s.top();
        if (s.size() != 1) cout << ' ';
        s.pop();
    }
    return 0;
}