# include <iostream>
using namespace std;

int main() {
    int *array = new int[20];
    int posCount = 0, nagCount = 0;
    cout<<"请输入n个整数，其中n不超过20:"<<endl;
    for (int i = 0; i < 20; i++) {
        cin >> array[i];
        if (array[i] > 0)posCount++;
        else if (array[i] < 0)nagCount++;
    }
    cout << "正数的个数是:" << posCount << endl;
    cout << "负数数的个数是:" << nagCount << endl;
    delete []array;

    return 0;
}
// 1 2 3 4 5 6 7 8 9 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 100