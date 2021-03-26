#include <bits/stdc++.h>

using namespace std;


int main() {
    list<int> list;
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(1);
    for (auto i: list)
        cout << i << ' ';
    cout << endl;
    //插入
    list.insert(++list.begin(), 99);
    for (auto i: list)
        cout << i << ' ';
    cout << endl;
    //里面的值
    list.remove(3);
    for (auto i: list)
        cout << i << ' ';

    return 0;
}