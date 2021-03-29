# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> box;
        backtrack(nums, box);
        return res;
    }

    //dfs,box放的是每一种情况
    void backtrack(vector<int> &nums, vector<int> &box) {
        if (box.size() == nums.size()) {
            res.push_back(box);
            return;
        }

        for (auto item:nums) {
            if (hasElem(item, box)) {
                continue;
            }
            box.push_back(item);
            backtrack(nums, box);
            box.pop_back();
        }
    }

    bool hasElem(int num, vector<int> &box) {
        for (int i = 0; i < box.size(); i++) {
            if (num == box[i])
                return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    Solution solution;
    vector<vector<int>> res = solution.permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }


    return 0;
}