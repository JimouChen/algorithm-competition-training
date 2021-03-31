# include <bits/stdc++.h>

using namespace std;
vector<int> flag(50);

class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, vector<int> &box) {
        if (nums.size() == box.size()) {
            res.push_back(box);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (flag[i]) continue;
            box.push_back(nums[i]);
            flag[i] = 1;
            backtrack(nums, box);
            box.pop_back();
            flag[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> box;
        backtrack(nums, box);
        return res;
    }
};

int main() {
    vector<int> nums{1, -2, 3};
    Solution s;
    vector<vector<int>> res = s.permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}