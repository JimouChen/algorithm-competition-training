#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //获取vector元素的个数
    map<int, int> getCount(vector<int> &node) {
        map<int, int> dict_res;
        for (int i = 0; i < node.size(); i++) {
            dict_res[node[i]]++;
        }
        return dict_res;
    }

    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return nullptr;
        vector<int> all_node;
        ListNode *p = head;
        while (p) {
            all_node.push_back(p->val);
            p = p->next;
        }
        map<int, int> count_res = getCount(all_node);
        vector<int> new_res;
        for (auto item: count_res) {
            if (item.second == 1) {
                new_res.push_back(item.first);
            }
        }
        int len = new_res.size();
        if (len == 0)return nullptr;

        ListNode *new_head = new ListNode[sizeof(ListNode)];
        new_head->val = new_res[0];
        ListNode *q = new_head;
        for (int i = 1; i < len; ++i) {
            ListNode *ne = new ListNode[sizeof(ListNode)];
            ne->val = new_res[i];
            new_head->next = ne;
            new_head = ne;
        }
        return q;
    }
};


int main() {
    Solution s;
    ListNode a1(1);
    ListNode a2(1);
    ListNode a3(2);
    ListNode a4(3);
    ListNode a5(49);
    ListNode a6(49);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    ListNode *res = s.deleteDuplicates(&a1);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
