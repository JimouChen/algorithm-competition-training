// π/4=1-1/3+1/5-1/7+……
#include <iostream>
using namespace std;

int main() {
    double pi = 0, fm = 1;
    int flag = 1;
    for (int i = 1; i <= 1000; i++) {
        pi += 1 / fm;
        flag = -flag;
        fm = (2 * i + 1) * flag;
    }
    cout << pi * 4 << endl;
    return 0;
}

