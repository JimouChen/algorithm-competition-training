#include <iostream>

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

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        bool exchange = true;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                exchange = false;
            }

        }
        if (exchange)return;
    }
}

//选择排序
void chooseSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        int minIndex = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex!=i){
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main() {
    int test[] = {3, 2, 7, 6, 9, 9, 1, 0, 54, 23};
//    insertSort(test, 10);
//    bubbleSort(test, 10);
    chooseSort(test, 10);
    for (int i = 0; i < 10; i++) {
        cout << test[i] << " ";
    }

    return 0;
}