#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<int> vec_to_set(vector<int> &v) {
        set<int> res;
        for (auto i:v) {
            res.insert(i);
        }
        return res;
    }

    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        set<int> res_set = vec_to_set(nums);
        long long n = nums.size();

        for (auto i:res_set) {
            long long c = 0;
            for (auto j:nums) {
                if (i == j) {
                    c++;
                }
                if (c > n / 3) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> v{1}, res;
    res = a.majorityElement(v);
    for (auto i:res) {
        cout << i << endl;
    }

    return 0;
}