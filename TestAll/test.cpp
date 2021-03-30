# include <bits/stdc++.h>

using namespace std;
vector<vector<int  >> res;

void show(vector<int> &nums) {
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
}

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return false;
    return true;
}

bool isInVector(vector<int> &box, int target) {
    for (int i = 0; i < box.size(); i++) {
        if (target == box[i]) return true;
    }
    return false;
}

bool isPrimeCle(vector<int> &b) {
    if (b[0] != 1) return false;
    b.push_back(b[0]);
    for (int i = 0; i < b.size() - 1; ++i) {
        if (!isPrime(b[i] + b[i + 1])) {
            b.pop_back();
            return false;
        }
    }
    b.pop_back();
    return true;

}

void backtrack(vector<int> &nums, vector<int> &box) {
    if (nums.size() == box.size() && isPrimeCle(box)) {
        show(box);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (isInVector(box, nums[i])) {
            continue;
        }
        box.push_back(nums[i]);
        backtrack(nums, box);
        box.pop_back();
    }
}

int main() {
    int n, cnt = 1;
    while (~scanf("%d", &n)) {
        vector<int> nums, box;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        cout << "Case " << cnt << endl;
        backtrack(nums, box);
        cnt++;
        cout << endl;
    };

    return 0;
}