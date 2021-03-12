#include <iostream>

using namespace std;

double average(double &max, double *min, double a[], int num) {
    double sum = 0;
    for (int i = 0; i < num; i++) {
        if (a[i] > max)max = a[i];
        else if (a[i] < *min)*min = a[i];
        sum += a[i];
    }
    return sum / num;
}


//double average1(double &max, double &min, double a[], int num) {
//    double sum = 0;
//    for (int i = 0; i < num; i++) {
//        if (a[i] > max)max = a[i];
//        else if (a[i] < min)min = a[i];
//        sum += a[i];
//    }
//    return sum / num;
//}

int main() {
    double a[10] = {2, 3, 4, 5, 1.9, 7, 4.2, 2.5, 211, 985};
    double maxNum = a[0], minNum = a[0];
    int num = 5;
    double aver = average(maxNum, &minNum, a, num);
//    double aver = average1(maxNum, minNum, a, num);
    cout << "前" << num << "个元素中:\n";
    cout << "最大值是:" << maxNum << endl;
    cout << "最小值是:" << minNum << endl;
    cout << "平均值是:" << aver << endl;
    return 0;
}