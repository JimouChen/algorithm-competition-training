# include <bits/stdc++.h>

using namespace std;
int flag[100] = {0};

void backtrack(vector<int> &nums, vector<int> &box) {
    if (nums.size() == box.size()) {
        for (int i = 0; i < box.size(); ++i) {
            cout << box[i]<<" ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (flag[i]) {
            continue;
        }
        box.push_back(nums[i]);
        flag[i] = 1;
        backtrack(nums, box);
        box.pop_back();
        flag[i] = 0;
    }

}


int main() {
    vector<int> nums{1, 3, -4};
    vector<int> box;
    backtrack(nums, box);

    return 0;
}