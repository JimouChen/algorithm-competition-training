# include<iostream>
# include <vector>
#include <algorithm>

using namespace std;
typedef struct {
    int rank;
    int value;
} A;

bool cmp(A a1, A a2) {
    return a1.value > a2.value;
}

int main() {
    cout << "\t\t\t��������Ҫ�������Ա����" << endl;
    cout << "*\t\t\t\t1-������\t\t\t\t*" << endl;
    cout << "*\t\t\t\t2-�о���\t\t\t\t*" << endl;
    cout << "*\t\t\t\t0-�˳�����ϵͳ\t\t\t*" << endl;

    return 0;
}

/**
Program function:
input the text from the keyboard, store it in
character vector, count the number of lines, words and letters.#
 */