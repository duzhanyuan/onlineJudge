/*
Cube Stacking
Time Limit: 2000MS		Memory Limit: 30000K
Total Submissions: 23768		Accepted: 8347
Case Time Limit: 1000MS
Description

Farmer John and Betsy are playing a game with N (1 <= N <= 30,000)identical cubes labeled 1 through N. They start with N stacks, each containing a single cube. Farmer John asks Betsy to perform P (1<= P <= 100,000) operation. There are two types of operations:
moves and counts.
* In a move operation, Farmer John asks Bessie to move the stack containing cube X on top of the stack containing cube Y.
* In a count operation, Farmer John asks Bessie to count the number of cubes on the stack with cube X that are under the cube X and report that value.

Write a program that can verify the results of the game.
Input

* Line 1: A single integer, P

* Lines 2..P+1: Each of these lines describes a legal operation. Line 2 describes the first operation, etc. Each line begins with a 'M' for a move operation or a 'C' for a count operation. For move operations, the line also contains two integers: X and Y.For count operations, the line also contains a single integer: X.

Note that the value for N does not appear in the input file. No move operation will request a move a stack onto itself.
Output

Print the output from each of the count operations in the same order as the input file.
Sample Input

6
M 1 6
C 1
M 2 4
M 2 6
C 3
C 4
Sample Output

1
0
2
Source

USACO 2004 U S Open

*/
#define _CRT_SECURE_NO_WARNINGS
#define maxN 30005
#include <cstdio>
using namespace std;
int par[maxN + 10];
int num[maxN + 10];//根节点指明该类的元素个数
int under[maxN + 10];//到根节点的元素个数差，物理上是到根节点的元素个数，实际意义代表的是x之下的元素
void init(int n) {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		num[i] = 1;
		under[i] = 0;
	}
}

int find(int x) {
	int fax = par[x];
	if (x != fax) {
		par[x] = find(par[x]);
		under[x] += under[fax];
	}
	return par[x];
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	par[x] = y;
	under[x] += num[y];
	num[y] += num[x];

}


int main() {
	int p;
	scanf("%d", &p);
	char c[10]; 
	init(maxN + 3);
	while (p--) {
		scanf("%s",c);
		if (c[0] == 'M') {
			int x; int y;
			scanf("%d %d", &x, &y);
			unite(x, y);
		}
		else {
			int x;
			scanf("%d", &x);
			find(x);
			printf("%d\n", under[x]);
		}
	}
	return 0;
}