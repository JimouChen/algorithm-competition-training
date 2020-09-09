#include <bits/stdc++.h>

using namespace std;

//找到子串返回索引,t是子串模板
int bf_index(string s, string t) {
    int k = 0;
    int i = k, j = 0;//i,j分别指向当前s,t的下标
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            k++;//继续检查下一个子串
            i = k;
            j = 0;
        }
    }
    if (j >= t.length())return k;//超出子串范围，此时的k就是匹配开始的位置
    else return 0;//匹配失败
}

int main() {
    string s = "123234r32r5";
    string t = "2r";
    cout << (bf_index(s, t));
    return 0;
}