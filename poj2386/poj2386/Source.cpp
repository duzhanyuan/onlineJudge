/*
Lake Counting
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 29697		Accepted: 14871
Description

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors.

Given a diagram of Farmer John's field, determine how many ponds he has.
Input

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.
Output

* Line 1: The number of ponds in Farmer John's field.
Sample Input

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
Sample Output

3
Hint

OUTPUT DETAILS:

There are three ponds: one in the upper left, one in the lower left,and one along the right side.
Source

USACO 2004 November

*/
//dfs简单练习题
#define _CRT_SECURE_NO_WARNINGS
#define maxN 100
#define maxM 100
#include <cstdio>
using namespace std;
int field[maxN][maxM];//0表示. 1表示w
int N,M;
void dfs(int x, int y) {
	field[x][y] = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = x + dx, ny = y + dy;//true location
			if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M)&&(field[nx][ny] == 1)) {
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	char a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &a);
			if (a == '.')
				field[i][j] = 0;
			else{
				field[i][j] = 1;//a=w
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 1) {
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}