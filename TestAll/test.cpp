#include<bits/stdc++.h>

using namespace std;

const int N = 1000;
int n;
int work[N][4]; //工作
int pos[N];  //当前位置

int shortest_time = (1 << 30); //先将结果置于无穷大
void dfs(int d, int tim1, int tim2, int t3) {  //深度，工厂1的时间  工厂2的时间 工厂3的时间(最终结果)

    if (t3 > shortest_time) return;//大于当前最优的结果退出，剪枝

    if (d > n) {
        if (t3 < shortest_time) {
            shortest_time = t3; //记录当前最小时间
        }
        return; //记得返回
    }

    for (int i = d; i <= n; i++) {
        int x = tim1, y = tim2, z = t3;

        tim1 += work[pos[i]][1];
        tim2 = (tim1 > tim2 ? tim1 : tim2) + work[pos[i]][2];
        t3 = (tim2 > t3 ? tim2 : t3) + work[pos[i]][3];
        //交换两个作业的位置，把选择出的原来在pos[i]位置上的任务调到当前执行的位置pos[d]
        swap(pos[d], pos[i]);
        dfs(d + 1, tim1, tim2, t3);
        swap(pos[d], pos[i]);

        tim1 = x, tim2 = y, t3 = z;//回溯
    }
}


int main() {
    cin >> n;// 几个作业
    for (int j = 1; j <= 3; j++)
        for (int i = 1; i <= n; i++) cin >> work[i][j];
    for (int j = 1; j <= 3; j++){
        for (int i = 1; i <= n; i++) cout << work[i][j] << " ";
        cout << "\n";
    }


    for (int i = 1; i <= n; i++) pos[i] = i;
    dfs(1, 0, 0, 0);
    cout << "最短时间:" << shortest_time << endl;
    cout << endl;
}

/*
test：
4
3 5 2 6
4 2 5 1
2 1 2 1

 18

4
5 3 2 6
4 2 5 1
2 1 2 1


4
5 3 2 1
4 2 5 1
2 1 2 1

*/

