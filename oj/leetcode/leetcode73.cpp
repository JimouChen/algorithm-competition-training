#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        set<int> zeroRaw;
        set<int> zeroCol;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeroRaw.insert(i);
                    zeroCol.insert(j);
                }
            }

        for (auto i: zeroCol)
            for (int j = 0; j < matrix.size(); j++)
                matrix[j][i] = 0;

        for (auto i: zeroRaw)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[i][j] = 0;
    }
};

int main() {


    return 0;
}