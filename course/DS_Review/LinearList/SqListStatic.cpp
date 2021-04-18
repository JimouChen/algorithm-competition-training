# include <bits/stdc++.h>

using namespace std;
#define maxsize 50
/** 静态顺序表*/
typedef int ElemType;
typedef struct {
    ElemType data[maxsize];
    int length;
} SqList;

void initList(SqList &L) {
    L.length = 0;
}

//在第i(0开始)个位置插入,这里根据题意来就行
bool insert(SqList &L, int i, int e) {
    if (i < 0 || i > L.length || L.length >= maxsize)
        return false;
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i] = e;
    L.length++;
    return true;
}

void display(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

int main() {
    SqList l;
    initList(l);
    for (int i = 1; i <= 10; i++) {
        insert(l, i - 1, i);
    }
    display(l);
    insert(l, 4, 666);
    display(l);
    return 0;
}