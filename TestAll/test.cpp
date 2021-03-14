#include <bits/stdc++.h>

using namespace std;


long long int get_s(long long int n) {
    long long int num = 0;
    while (n != 0) {
        num = num + n % 10;
        n = n / 10;
    }
    return num;
}

int get_len(vector<long long int> &v) {
    int c = 0;
    for (auto i : v) {
        c++;
    }
    return c;
}

long long int get_qiann(vector<long long int> &v1, int n) {
    long long int sum = 0;
    int c = 0;
    for (auto i : v1) {
        if (c == n)break;
        c++;
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<long long int >> all;
    for (int t = 1; t <= 50; t++) {
        vector<long long int> a;
        int flag = 0;
        for (int i = 0; i <= 100000; i++) {
            long long int s = get_s(i);
            if (s == t) {
                a.push_back(i);
                flag = 1;
            }
        }
        if (flag == 0)break;
        all.push_back(a);
    }
    long long int min_ = 999999999;
    for (auto e  : all) {
        if (get_len(e) >= n) {
            min_ = min(min_, get_qiann(e, n));
        }
    }
    cout<<min_;


    return 0;
}