#include <iostream>
using namespace std;

template<class T>
int search(T list[], T key, int n) {
    for (int i = 0; i < n; ++i) {
        if (key == list[i]) return i;
    }
    return -1;
}

template<class T>
void input(T list[], int &n) {
    cout << "请输入一个正整数n(n <= 20):" << endl;
    cin >> n;
    cout << "请输入" << n << "个数:" << endl;
    for (int i = 0; i < n; ++i)
        cin >> list[i];
}

int main() {
    int testInt[20], n = 0;
    char testChar[20];
    int key1;
    char key2;

    input(testInt, n);
    cout << "请输入需要查找的整型数值" << endl;
    cin >> key1;
    cout << "下标是：" << search(testInt, key1, 5) << endl;

    input(testChar, n);
    cout << "请输入需要查找的字符型数值" << endl;
    cin >> key2;
    cout << "下标是：" << search(testChar, key2, 5) << endl;

    return 0;
}