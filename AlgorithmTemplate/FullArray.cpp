#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char arr[] = {'c', 'b', 'a'};
    cout << "用prev_permutation对3 2 1的全排列" << endl;
    do {
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
    } while (prev_permutation(arr, arr + 3));      ///获取上一个较大字典序排列，如果3改为2，只对前两个数全排列

    int arr1[] = {1, 2, 3, 4};
    cout << "用next_permutation对1 2 3 4的全排列" << endl;
    do {
        cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << ' '<< arr1[3] << '\n';
    } while (next_permutation(arr1, arr1 + 4));      ///获取下一个较大字典序排列，如果3改为2，只对前两个数全排列
    ///注意数组顺序，必要时要对数组先进行排序

    return 0;
}
