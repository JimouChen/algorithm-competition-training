#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "������������Сn��" << endl;
    cin >> n;
    vector<int> v(n);

    cout << "������n������" << endl;
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
    int key;
    cout << "��������Ҫͳ�Ƹ�����ֵ:" << endl;
    cin >> key;
    cout << "ֵΪ" << key << "����һ������:" << count(v.begin(), v.end(), key) << "��" << endl;
    return 0;
}