#ifndef ALGORITHM_COMPETITION_TRAINING_SQLISTSTATIC_H
#define ALGORITHM_COMPETITION_TRAINING_SQLISTSTATIC_H

//# include <bits//stdc++.h>
//
//using namespace std;
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

//删除第i个
bool deleteElem(SqList &L, int i, int &e) {
    if (i < 0 || i >= L.length)
        return false;
    e = L.data[i];
    for (int j = i; j < L.length - 1; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

// 按位查找(1开始)，找第i个
ElemType getElem1(SqList L, int i) {
    if (i < 0 || i >= L.length) {
        cout << "i 不合法" << endl;
    } else return L.data[i - 1];
}

//按值查找，返回下标
ElemType getElem2(SqList L, int value) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == value) {
            return i;
        }
    }
    return -1;//找不到
}

void display(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

void reverseList(SqList &L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

void deleteAllX(SqList &L, int x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

//删除递增有序表中值在s到t之间的元素
bool deleteSToT(SqList &L, int s, int t) {
    if (!L.length || s > t) return false;
    int k = 0, firstIndex, lastIndex;
    for (int i = 0; i < L.length; i++)
        if (L.data[i] >= s) {
            firstIndex = i;
            break;
        }
    for (int i = L.length - 1; i >= firstIndex; i--) {
        if (L.data[i] <= t) {
            lastIndex = i;
            break;
        }
    }
    k = lastIndex - firstIndex + 1;
    for (int i = firstIndex; i < L.length; i++) {
        L.data[i] = L.data[i + k];
    }
    L.length -= k;
    return true;
}

//删除无序表s到t之间的元素，包括s，t
bool deleteS2T(SqList &L, int s, int t) {
    if (L.length == 0)return false;
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t) k++;
        else L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;
}

//删除有序表所有重复的元素
bool deleteSame(SqList &L) {
    if (L.length == 0)return false;
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == L.data[i + 1] || L.data[i - 1] == L.data[i]) {
            k++;
        } else L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;
}

//合并两个有序表
bool mergeOrderList(SqList L1, SqList L2, SqList &L3) {
    if (L1.length + L2.length > maxsize)return false;
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j])
            L3.data[k++] = L1.data[i++];
        else
            L3.data[k++] = L2.data[j++];
    }
    //剩余部分
    while (i < L1.length) L3.data[k++] = L1.data[i++];
    while (j < L2.length) L3.data[k++] = L2.data[j++];
    L3.length = k;
    return true;
}

// p17-9
void findAndExchange(SqList &L, int x) {
    int mid, left = 0, right = L.length - 1, i;
    while (left <= right) {
        mid = (left + right) / 2;
        if (L.data[mid] == x)break;
        else if (L.data[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    if (L.data[mid] == x && mid != L.length - 1) {
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = x;
    }
    if (left > right) {//找不到的情况就按序插入,在right+1的位置插入
        for (i = L.length - 1; i > right; i--)
            L.data[i + 1] = L.data[i];
        L.data[i + 1] = x;
        L.length += 1;
    }
}

//p17-10
void reserveFromS2T(SqList &L, int left, int right) {
    int temp;
    for (int i = left; i <= (left + right) / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[right - i];
        L.data[right - i] = temp;
    }
}

void use(SqList &L, int p) {
    reserveFromS2T(L, 0, L.length - 1);
    reserveFromS2T(L, 0, L.length - 1 - p);
    reserveFromS2T(L, L.length - p, L.length - 1);
}

#endif //ALGORITHM_COMPETITION_TRAINING_SQLISTSTATIC_H
