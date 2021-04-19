# include <bits/stdc++.h>

# define initLength 20
using namespace std;
/** 动态顺序表*/
typedef int ElemType;
typedef struct {
    ElemType *data;
    int maxsize;
    int length;
} SeqList;

void initList(SeqList &L) {
    L.data = (ElemType *) malloc(sizeof(ElemType) * initLength);
    L.length = 0;
    L.maxsize = initLength;
}

void increaseLength(SeqList &L, int len) {
    ElemType *p = L.data;//为了把原来的元素移动到新的空间
    L.maxsize += len;
    L.data = (ElemType *) malloc(sizeof(ElemType) * L.maxsize);
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    free(p);
}
// 按位查找(1开始)，找第i个
ElemType getElem1(SeqList L, int i) {
    if (i < 0 || i >= L.length) {
        cout << "i 不合法" << endl;
    } else return L.data[i - 1];
}
int main() {
    return 0;
}
