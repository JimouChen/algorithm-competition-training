/*最小公倍数*/
//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int num(int a, int b) {
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int tem = 0;
    while (min) {
        tem = min;
        min = max % tem;
        max = tem;
        //cout<<max<<'/'<<min<<endl;
    }
    return max;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ji = a * b * c;
    int num1 = num(a, b);
    int num2 = num(b, c);
    cout << ji / num1 / num2 << endl;
    return 0;
}