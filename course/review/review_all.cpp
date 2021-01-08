# pragma once

# include <iostream>

using namespace std;

void bubble(int a[], int n) {
    int e = n - 1, bound = 0;
    while (e) {
        bound = e;
        e = 0;
        for (int i = 0; i < bound; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                e = i;//记录交换的位置
            }
        }
    }
}

int BF(char s[], char t[]) {
    int index = 0, i = 0, j = 0;
    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            index++;
            i = index;
        }
    }
    if (t[j] == '\0')
        return index + 1;
    else return -1;
}

void merge(int r[], int r1[], int s, int m, int t) {
    int i = s, j = m + 1, k = s;

    while (i <= m && j <= t) {
        if (r[i] <= r[j]) {
            r1[k++] = r[i++];
        } else
            r1[k++] = r[j++];
//        r1[k++] = (r[i] <= r[j]) ? r[i++] : r[j++];
    }

    while (i <= m)
        r1[k++] = r[i++];
    while (j <= t)
        r1[k++] = r[j++];
}

void mergeSort(int r[], int s, int t) {
    int m, new_array[1000];
    if (s == t)return;
    else {
        m = (s + t) / 2;
        mergeSort(r, s, m);
        mergeSort(r, m + 1, t);
        merge(r, new_array, s, m, t);
    }
    //r = new_array
    for (int i = s; i <= t; i++)
        r[i] = new_array[i];
}

int main() {
    cout << "hello\n";
    int test[] = {4, 5, 2, 1, 6, 7, 8};
    int test1[] = {4, 5, 2, 1, 6, 7, 66, 8};
    bubble(test, 7);
    for (int i : test)
        cout << i << " ";
    cout << endl;
    cout << "从第" << BF("abcdefg", "efg") << "字母开始\n";
    mergeSort(test1, 0, 8);
    for (int i : test1) {
        cout << test1[i] << " ";
    }
    return 0;
}