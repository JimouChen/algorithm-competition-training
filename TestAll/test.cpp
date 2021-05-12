#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "请输入容器大小n：" << endl;
    cin >> n;
    vector<int> v(n);

    cout << "请输入n个整数" << endl;
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
    int key;
    cout << "请输入需要统计个数的值:" << endl;
    cin >> key;
    cout << "值为" << key << "的数一共出现:" << count(v.begin(), v.end(), key) << "次" << endl;
    return 0;
}