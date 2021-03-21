# include <bits/stdc++.h>

using namespace std;

//摆动排序Ⅱ
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.rbegin(), nums.rend());
        int len = nums.size();
        vector<int> temp(len);
        for (int i = len / 2, j = 0; i < len; ++i, j += 2)
            temp[j] = nums[i];
        for (int i = 0, j = 1; i < len / 2; ++i, j += 2)
            temp[j] = nums[i];
        nums = temp;
    }
};

int main() {
    vector<int> v{1, 2, 2, 3};
    Solution s;
    s.wiggleSort(v);
    for (auto i:v)
        cout << i << " ";

    return 0;
}