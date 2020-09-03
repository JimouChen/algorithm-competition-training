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
    cout << tenToTwo(11);
    return 0;
}