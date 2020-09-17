# include <iostream>

using namespace std;

int T(int n) {
    if (n == 1)
        return 1;
    else if (n > 1)
        return 2 * T(n / 3) + n;
}

int main() {
    cout<<T(5);
    return 0;
}