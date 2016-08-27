/*
Fliptile
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 7643		Accepted: 2876
Description

Farmer John knows that an intellectually satisfied cow is a happy cow who will give more milk. He has arranged a brainy activity for cows in which they manipulate an M × N grid (1 ≤ M ≤ 15; 1 ≤ N ≤ 15) of square tiles, each of which is colored black on one side and white on the other side.

As one would guess, when a single white tile is flipped, it changes to black; when a single black tile is flipped, it changes to white. The cows are rewarded when they flip the tiles so that each tile has the white side face up. However, the cows have rather large hooves and when they try to flip a certain tile, they also flip all the adjacent tiles (tiles that share a full edge with the flipped tile). Since the flips are tiring, the cows want to minimize the number of flips they have to make.

Help the cows determine the minimum number of flips required, and the locations to flip to achieve that minimum. If there are multiple ways to achieve the task with the minimum amount of flips, return the one with the least lexicographical ordering in the output when considered as a string. If the task is impossible, print one line with the word "IMPOSSIBLE".

Input

Line 1: Two space-separated integers: M and N
Lines 2..M+1: Line i+1 describes the colors (left to right) of row i of the grid with N space-separated integers which are 1 for black and 0 for white
Output

Lines 1..M: Each line contains N space-separated integers, each specifying how many times to flip that particular location.
Sample Input

4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1
Sample Output

0 0 0 0
1 0 0 1
1 0 0 1
0 0 0 0
Source

USACO 2007 Open Silver
*/
//PCCB ex3.2.2 翻转问题 主要学习字典序枚举的方法
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxM 20
#define maxN 20
int map[maxM][maxN];
int opt[maxM][maxN];//best answer
int flip[maxM][maxN];//current answer
int M, N;
int dir[5][2] = { {0,0},{1,0},{-1,0},{0,1},{0,-1} };
int get(int x0, int y0) {//return the color of map[x][y]
	int res = map[x0][y0];
	int x, y;
	for (int i = 0; i < 5; i++) {
		x = x0 + dir[i][0];
		y = y0 + dir[i][1];
		if (0 <= x && x < M && 0 <= y && y < N) {
			res += flip[x][y];
		}
	}
	return res % 2;

}
int calc() {//calculate the times needed, if impossible, return -1
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < N; j++) {
			flip[i][j] = get(i - 1, j);
		}
	}
	for (int j = 0; j < N; j++) {
		if (get(M - 1, j) != 0) {
			return -1;
		}
	}
	int res = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			res += flip[i][j];
		}
	}
	return res;
}
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int res = -1;
	for (int i = 0; i < 1 << N; i++) {//enum all the possibiltie by lexicograhphical order
		memset(flip, 0, sizeof(flip));
		for (int j = 0; j < N; j++) {
			flip[0][N - j - 1] = i >> j & 1;
		}
		int m = calc();
		if (m >= 0 && (res  <0 || res > m)) {
			res = m;
			memcpy(opt, flip, sizeof(opt));
		}
	}
	if (res == -1) {
		printf("IMPOSSIBLE\n");
	}
	else {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", opt[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}