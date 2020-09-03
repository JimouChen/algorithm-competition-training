#include <bits/stdc++.h>

using namespace std;

template<class T>
void showMsg(vector<T> msg) {
//    for (int j = 0; j < msg.size(); ++j)
//        cout << msg[j] << ' ';
//
    auto p = msg.begin();
    for (p; p < msg.end(); p++) {
        cout << *p << ' ';
    }
    cout << '\n';
}

int main() {
    vector<char> msg;
    char next;
    cin.get(next);
    while (next != '\n') {
        msg.push_back(next);
        cin.get(next);
    }
    showMsg(msg);
    //change value
    msg[2] = 'e';
    showMsg(msg);
    //reverse
    reverse(msg.begin(), msg.end());
    showMsg(msg);
    int n;
    vector<int> In;
    cin>>n;
    while (n--){
        int v;
        cin>>v;
        In.push_back(v);
    }
    reverse(In.begin(), In.end());
    sort(In.rbegin(), In.rend());

    showMsg(In);

    return 0;
}