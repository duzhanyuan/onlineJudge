/*
�Թ�����
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 16264		Accepted: 9710
Description

����һ����ά���飺

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�
Input

һ��5 �� 5�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ�⡣
Output

���Ͻǵ����½ǵ����·������ʽ��������ʾ��
Sample Input

0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output

(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
Source
*/
//�򵥵Ŀ����������bfs ����¼·������
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <functional>
#define INF 100000
using namespace std;
typedef pair<int, int> P;

int map[6][6];
int d[6][6];//��̾���
P step[6][6];//��¼��һ��
int sx=4, sy=4;
int gx=0, gy=0;//�������������������
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void bfs() {
	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	while (!que.empty()) {
		P p = que.front(); que.pop();
		if (p.first == gx && p.second == gy)break;
		for (int i = 0; i < 4; i++) {
			int x = p.first + dir[i][0];
			int y = p.second + dir[i][1];
			if (0 <= x && x < 5 && 0 <= y && y < 5 && map[x][y] != 1 && d[x][y] == INF) {
				que.push(P(x, y));
				d[x][y] = d[p.first][p.second] + 1;
				step[x][y] = P(p.first, p.second);
			}
		}
	}

}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &map[i][j]);
			d[i][j] = INF;
		}
	}
	bfs();
	printf("(0, 0)\n");
	P p = step[gx][gy];
	while (!(p.first == sx && p.second == sy)) {
		printf("(%d, %d)\n", p.first, p.second);
		p = step[p.first][p.second];
	}
	printf("(4, 4)\n");

	return 0;
}