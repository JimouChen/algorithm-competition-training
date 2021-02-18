#include<bits/stdc++.h>

using namespace std;

const int N = 1000;
int n;
int work[N][4]; //����
int pos[N];  //��ǰλ��

int shortest_time = (1 << 30); //�Ƚ�������������
void dfs(int d, int tim1, int tim2, int t3) {  //��ȣ�����1��ʱ��  ����2��ʱ�� ����3��ʱ��(���ս��)

    if (t3 > shortest_time) return;//���ڵ�ǰ���ŵĽ���˳�����֦

    if (d > n) {
        if (t3 < shortest_time) {
            shortest_time = t3; //��¼��ǰ��Сʱ��
        }
        return; //�ǵ÷���
    }

    for (int i = d; i <= n; i++) {
        int x = tim1, y = tim2, z = t3;

        tim1 += work[pos[i]][1];
        tim2 = (tim1 > tim2 ? tim1 : tim2) + work[pos[i]][2];
        t3 = (tim2 > t3 ? tim2 : t3) + work[pos[i]][3];
        //����������ҵ��λ�ã���ѡ�����ԭ����pos[i]λ���ϵ����������ǰִ�е�λ��pos[d]
        swap(pos[d], pos[i]);
        dfs(d + 1, tim1, tim2, t3);
        swap(pos[d], pos[i]);

        tim1 = x, tim2 = y, t3 = z;//����
    }
}


int main() {
    cin >> n;// ������ҵ
    for (int j = 1; j <= 3; j++)
        for (int i = 1; i <= n; i++) cin >> work[i][j];
    for (int j = 1; j <= 3; j++){
        for (int i = 1; i <= n; i++) cout << work[i][j] << " ";
        cout << "\n";
    }


    for (int i = 1; i <= n; i++) pos[i] = i;
    dfs(1, 0, 0, 0);
    cout << "���ʱ��:" << shortest_time << endl;
    cout << endl;
}

/*
test��
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

