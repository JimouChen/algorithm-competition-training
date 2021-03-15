# include <bits/stdc++.h>

using namespace std;

//螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int raw = matrix.size(), col = matrix[0].size();
        int left = 0, right = col - 1, up = 0, down = raw - 1;
        while (left <= right && up <= down) {
            for (int i = left; i <= right; i++)//上
                res.push_back(matrix[up][i]);
            for (int i = up + 1; i < down; i++)//右
                res.push_back(matrix[i][right]);
            if (up != down)
                for (int i = right; i >= left; i--)//下
                    res.push_back(matrix[down][i]);
            if (right != left)
                for (int i = down - 1; i > up; i--)//左
                    res.push_back(matrix[i][left]);
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<vector<int>> v{{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    vector<int > res = a.spiralOrder(v);
    for (auto i:res){
        cout<<i<<" ";
    }

    return 0;
}