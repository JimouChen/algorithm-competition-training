# include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp;
    vector<int> temp(m + 1);
    dp.resize(n + 1, temp);
    vector<int> weight{0, 2, 3, 4};
    vector<int> value{0, 3, 5, 7};


    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++) {
            if (weight[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "best value: " << dp[n][m];
    return 0;
}
/**
3 5

2 3
3 5
4 7


 output: 8
 */