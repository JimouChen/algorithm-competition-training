# include<iostream>
# include <vector>
#include <algorithm>
using namespace std;

int getLitterNum(vector<char> &v) {
    int letterCount = 0;
    for (int i = 0; i < v.size(); i++)
        if ((v[i] >= 'a' && v[i] <= 'z') || (v[i] >= 'A' && v[i] <= 'Z'))
            letterCount++;
    return letterCount;
}

int main() {
    vector<char> v;
    char next;
    int rawCount, wordCount, letterCount;

    cout << "请输入一段文本(以#结束):" << endl;
    cin.get(next);
    while (next != '#') {
        v.push_back(next);
        cin.get(next);
    }
    //统计文本的行数、单词数以及字母出现的次数
    rawCount = count(v.begin(), v.end(), '\n') + 1;
    wordCount = count(v.begin(), v.end(), ' ') + 1;
    letterCount = getLitterNum(v);

    cout << "文本行数: " << rawCount << endl;
    cout << "单词个数: " << wordCount << endl;
    cout << "字母个数: " << letterCount << endl;

    return 0;
}

/**
Program function:
input the text from the keyboard, store it in
character vector, count the number of lines, words and letters.#
 */