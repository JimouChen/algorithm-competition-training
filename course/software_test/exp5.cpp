# include <iostream>

using namespace std;

void judge(int a, int b, int c) {
    int theta = b * b - 4 * a * c;
    if (a < -200 || a > 200 || b < -200 || b > 200 || c < -200 || c > 200)
        cout << "�������\n";
    else {
        if (a == 0) {
            if (b == 0) {
                if (c == 0)
                    cout << "A*x^2+B*x+C ����������\n";
                else cout << "A*x^2+B*x+C �޸�\n";
            } else cout << "A*x^2+B*x+C ��һ��ʵ��\n";
        } else { //a!=0�����
            if (theta > 0)
                cout << "A*x^2+B*x+C ����������ȵ�ʵ����\n";
            else if (theta == 0)
                cout << "A*x^2+B*x+C ��������ȵ�ʵ����\n";
            else
                cout << "A*x^2+B*x+C ���������\n";
        }
    }
}

int main() {
    int a, b, c;
    cout << "������A*x^2+B*x+C ��ϵ��A��B��C: ";
    while (cin >> a >> b >> c){
        judge(a, b, c);
        cout << "������A*x^2+B*x+C ��ϵ��A��B��C: ";
    }

    return 0;
}


