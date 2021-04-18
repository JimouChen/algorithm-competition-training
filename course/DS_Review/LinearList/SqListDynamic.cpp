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

int main() {
    return 0;
}
