# include <bits/stdc++.h>

using namespace std;

#include "SqListStatic.h"

/** 静态顺序表*/



int main() {
    SqList l;
    initList(l);
    for (int i = 1; i <= 10; i++) {
        insert(l, i - 1, i);
    }
    display(l);
    insert(l, 4, 666);
    display(l);
    int e;
    deleteElem(l, 4, e);
    display(l);
    cout << "e = " << e << endl;
    cout << "find 7th:" << getElem1(l, 7) << endl;
    cout << "test reverse\n";
    reverseList(l);
    display(l);
    for (int i = 0; i < 3; i++)insert(l, i + 5, 666);
    for (int i = 0; i < 3; i++)insert(l, i + 5, 555);
    display(l);
//    deleteAllX(l, 666);
//    display(l);
    reverseList(l);

    display(l);
//    deleteSToT(l, 2, 5);
    deleteS2T(l, 2, 6);
    display(l);
    deleteSame(l);
    display(l);
    SqList L2, L1;
    initList(L1);
    initList(L2);
    for (int i = 0; i < 10; i++)insert(L2, i, i);
    for (int i = 0; i < 10; i++)insert(L1, i, i);
    display(L1);
    display(L2);
    SqList L3;
    initList(L3);
    mergeOrderList(L1, L2, L3);
    display(L3);
    return 0;
}