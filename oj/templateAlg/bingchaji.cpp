#include <bits/stdc++.h>

using namespace std;
#define MaxN 100
/**并查集*/

int father[MaxN];

void init_father(int n) {
    for (int i = 0; i <= n; ++i)
        father[i] = i;
}

//找到祖先节点
int find_root(int son) {
    if (son == father[son])
        return son;
    father[son] = find_root(father[son]);//剪枝
    return father[son];
}

//合并节点
void union_node(int son1, int son2) {
    int son1_root = find_root(son1);
    int son2_root = find_root(son2);
    //把节点2的祖先作为节点1的祖先
    father[son1_root] = son2_root;
}

int main() {
    int n, m;//n人，m组关系
    cin >> n >> m;
    int a, b;
    init_father(n);
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        union_node(a, b);
    }

    int c;//输入n组判断是不是亲戚
    cin >> c;
    while (c--) {
        cin >> a >> b;
        if (find_root(a) == find_root(b))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}
/**
10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
7 10
8 9

 */