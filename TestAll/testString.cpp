#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "1523525431873";
    for (int i = 0; i < s.length(); ++i)
        cout << s[i];

    cout << '\n';
    for (string::iterator iter = s.begin(); iter != s.end(); iter++)
        cout << *iter;

    cout << '\n';
    for (auto i : s)
        cout << i;


    cout << endl << s;
    return 0;
}