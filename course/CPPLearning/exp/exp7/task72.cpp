# include<iostream>

using namespace std;

template<class T>
void sortBubble(T a[], int n) {
    for (int i = 0; i < n; ++i) {
        bool exchangeFlag = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                exchangeFlag = true;
            }
        }
        if (!exchangeFlag)break;
    }
}

template<class T>
void input(T list[], int &n) {
    cout << "请输入一个正整数n(n <= 20):" << endl;
    cin >> n;
    cout << "请输入" << n << "个数:" << endl;
    for (int i = 0; i < n; ++i)
        cin >> list[i];
}

int main() {
    int A[20];
    char B[20];
    int n = 0;
    input(A, n);
    sortBubble(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    input(B, n);
    sortBubble(B, n);
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    return 0;
}