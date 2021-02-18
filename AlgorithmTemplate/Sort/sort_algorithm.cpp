#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

void insertSort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}

int main() {
    int test[] = {3, 2, 7, 6, 9, 9, 1, 0, 54, 23};
    insertSort(test, 10);
    for (int i = 0; i < 10; i++) {
        cout << test[i] << " ";
    }

    return 0;
}