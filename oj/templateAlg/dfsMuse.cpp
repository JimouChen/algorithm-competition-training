# include <bits/stdc++.h>

using namespace std;
int flag[100][100];
int graph[100][100];//1是空地，2是障碍物
int minDis = 999999;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int px = 0, py = 0;//目的坐标

void dfs(int x, int y, int step) {
    if (x == px && y == py) {
        minDis = min(minDis, step);
        return;
    }


    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (graph[tx][ty] == 1 && flag[tx][ty] == 0) {
            flag[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            flag[tx][ty] = 0;
        }
    }
}

int main() {
    int m, n;//n行m列
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    int startX = 0, startY = 0;
    cin >> px >> py;
    flag[startX][startY] = 1;
    dfs(startX, startY, 0);
    cout << minDis << endl;
    return 0;
}
/**

5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
3 2

 */