#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char arr[] = {'c', 'b', 'a'};
    cout << "��prev_permutation��3 2 1��ȫ����" << endl;
    do {
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
    } while (prev_permutation(arr, arr + 3));      ///��ȡ��һ���ϴ��ֵ������У����3��Ϊ2��ֻ��ǰ������ȫ����

    int arr1[] = {1, 2, 3, 4};
    cout << "��next_permutation��1 2 3 4��ȫ����" << endl;
    do {
        cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << ' '<< arr1[3] << '\n';
    } while (next_permutation(arr1, arr1 + 4));      ///��ȡ��һ���ϴ��ֵ������У����3��Ϊ2��ֻ��ǰ������ȫ����
    ///ע������˳�򣬱�ҪʱҪ�������Ƚ�������

    return 0;
}
