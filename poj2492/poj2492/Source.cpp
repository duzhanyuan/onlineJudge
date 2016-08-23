/*
A Bug's Life
Time Limit: 10000MS		Memory Limit: 65536K
Total Submissions: 34528		Accepted: 11288
Description

Background
Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs.
Problem
Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input

The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
Output

The output for every scenario is a line containing "Scenario #i:", where i is the number of the scenario starting at 1, followed by one line saying either "No suspicious bugs found!" if the experiment is consistent with his assumption about the bugs' sexual behavior, or "Suspicious bugs found!" if Professor Hopper's assumption is definitely wrong.
Sample Input

2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
Sample Output

Scenario #1:
Suspicious bugs found!

Scenario #2:
No suspicious bugs found!
Hint

Huge input,scanf is recommended.
Source

TUD Programming Contest 2005, Darmstadt, Germany

*/
#define _CRT_SECURE_NO_WARNINGS
#define maxN 2000
#include <cstdio>
using namespace std;
int par[2 * maxN + 1];
int rank[2 * maxN + 1];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x) {
	if (x == par[x]) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] == rank[y])rank[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int T;
	scanf("%d", &T);
	int n, m,x,y;
	bool flag = false;
	for (int t = 1; t <= T; t++) {
		flag = false;
		scanf("%d %d", &n, &m);
		init(2 * n + 1);
		while (m--) {
			scanf("%d %d", &x, &y);
			unite(x, y + n);
			unite(y, x + n);
			if (same(x, x + n) || same(y, y + n)) {
				flag = true;
			}
		}
		printf("Scenario #%d:\n", t);
		if (flag) {
			printf("Suspicious bugs found!\n");
		}
		else {
			printf("No suspicious bugs found!\n");
		}
		printf("\n");
	}
	return 0;
}