# include <iostream>

using namespace std;

int main() {
    long long val = 0, count = 0;

    while (true) {

        val = val * 10 + 1;
        count++;
        if (val % 111111 == 0) {
            cout << count << endl;
            break;
        }
    }


    return 0;
}