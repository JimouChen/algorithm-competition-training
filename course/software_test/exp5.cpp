# include <iostream>

using namespace std;

void judge(int a, int b, int c) {
    int theta = b * b - 4 * a * c;
    if (a < -200 || a > 200 || b < -200 || b > 200 || c < -200 || c > 200)
        cout << "输入错误\n";
    else {
        if (a == 0) {
            if (b == 0) {
                if (c == 0)
                    cout << "A*x^2+B*x+C 有无数个根\n";
                else cout << "A*x^2+B*x+C 无根\n";
            } else cout << "A*x^2+B*x+C 有一个实根\n";
        } else { //a!=0的情况
            if (theta > 0)
                cout << "A*x^2+B*x+C 有两个不相等的实数根\n";
            else if (theta == 0)
                cout << "A*x^2+B*x+C 有两个相等的实数根\n";
            else
                cout << "A*x^2+B*x+C 有两个虚根\n";
        }
    }
}

int main() {
    int a, b, c;
    cout << "请输入A*x^2+B*x+C 的系数A、B、C: ";
    while (cin >> a >> b >> c){
        judge(a, b, c);
        cout << "请输入A*x^2+B*x+C 的系数A、B、C: ";
    }

    return 0;
}


