/*
Hopscotch
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 3350		Accepted: 2311
Description

The cows play the child's game of hopscotch in a non-traditional way. Instead of a linear set of numbered boxes into which to hop, the cows create a 5x5 rectilinear grid of digits parallel to the x and y axes.

They then adroitly hop onto any digit in the grid and hop forward, backward, right, or left (never diagonally) to another digit in the grid. They hop again (same rules) to a digit (potentially a digit already visited).

With a total of five intra-grid hops, their hops create a six-digit integer (which might have leading zeroes like 000201).

Determine the count of the number of distinct integers that can be created in this manner.
Input

* Lines 1..5: The grid, five integers per line
Output

* Line 1: The number of distinct integers that can be constructed
Sample Input

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1
Sample Output

15
Hint

OUTPUT DETAILS:
111111, 111112, 111121, 111211, 111212, 112111, 112121, 121111, 121112, 121211, 121212, 211111, 211121, 212111, and 212121 can be constructed. No other values are possible.
Source

USACO 2005 November Bronze

*/

#include <iostream>
#include <set>
using namespace std;
int a[5][5];
set<int> ans;
int direct[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void dfs(int x0, int y0, int step, int num) {
	if (step == 6) {
		ans.insert(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x = x0 + direct[i][0];
		int y = y0 + direct[i][1];
		if (x >= 0 && x < 5 && y >= 0 && y < 5) {
			int b = 10 * num + a[x][y];
			dfs(x, y, step + 1, b);

		}

	}

}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, 0);
		}
	}
	printf("%d\n", ans.size());
	return 0;
}