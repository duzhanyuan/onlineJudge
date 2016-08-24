/*
Red and Black
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 31097		Accepted: 16967
Description

There is a rectangular room, covered with square tiles. Each tile is colored either red or black. A man is standing on a black tile. From a tile, he can move to one of four adjacent tiles. But he can't move on red tiles, he can move only on black tiles.

Write a program to count the number of black tiles which he can reach by repeating the moves described above.
Input

The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and H are the numbers of tiles in the x- and y- directions, respectively. W and H are not more than 20.

There are H more lines in the data set, each of which includes W characters. Each character represents the color of a tile as follows.

'.' - a black tile
'#' - a red tile
'@' - a man on a black tile(appears exactly once in a data set)
The end of the input is indicated by a line consisting of two zeros.
Output
For each data set, your program should output a line which contains the number of tiles he can reach from the initial tile (including itself).
Sample Input

6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
Sample Output

45
59
6
13
Source

Japan 2004 Domestic

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define maxW 21
#define maxH 21
using namespace std;
int a[maxW][maxH];//0表示.(可以走) 1表示#(没法走)
int ans, w, h, x0, y0;
char temp;
void dfs(int x, int y) {
	a[x][y] = 1;
	ans++;
	if ((x - 1) >= 0 && (x - 1) < h&&a[x - 1][y] == 0)dfs(x - 1, y);
	if ((x + 1) >= 0 && (x + 1) < h&&a[x + 1][y] == 0)dfs(x + 1, y);
	if ((y - 1) >= 0 && (y - 1) < w&&a[x][y - 1] == 0)dfs(x, y - 1);
	if ((y + 1) >= 0 && (y + 1) < w&&a[x][y + 1] == 0)dfs(x, y + 1);
	return;
}
int main() {
	while (true) {
		scanf("%d%d", &w, &h);
		if (w == 0 && h == 0)break;
		ans = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %c", &temp);
				if (temp == '.') {
					a[i][j] = 0;
				}
				else if (temp == '#') {
					a[i][j] = 1;
				}
				else if (temp == '@') {
					a[i][j] = 0;
					x0 = i; y0 = j;
				}
			}
		}
		dfs(x0, y0);
		printf("%d\n", ans);
	}
	return 0;
}