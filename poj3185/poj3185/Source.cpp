/*
The Water Bowls
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 5919		Accepted: 2335
Description

The cows have a line of 20 water bowls from which they drink. The bowls can be either right-side-up (properly oriented to serve refreshing cool water) or upside-down (a position which holds no water). They want all 20 water bowls to be right-side-up and thus use their wide snouts to flip bowls.

Their snouts, though, are so wide that they flip not only one bowl but also the bowls on either side of that bowl (a total of three or -- in the case of either end bowl -- two bowls).

Given the initial state of the bowls (1=undrinkable, 0=drinkable -- it even looks like a bowl), what is the minimum number of bowl flips necessary to turn all the bowls right-side-up?
Input

Line 1: A single line with 20 space-separated integers
Output

Line 1: The minimum number of bowl flips necessary to flip all the bowls right-side-up (i.e., to 0). For the inputs given, it will always be possible to find some combination of flips that will manipulate the bowls to 20 0's.
Sample Input

0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0
Sample Output

3
Hint

Explanation of the sample:

Flip bowls 4, 9, and 11 to make them all drinkable:
0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [initial state]
0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [after flipping bowl 4]
0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 [after flipping bowl 9]
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 [after flipping bowl 11]
Source

USACO 2006 January Bronze

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int map[21];
int press1[22];
int getStat1(int i) {//1 <= i <= 20
	int c = map[i] + press1[i - 1] + press1[i] + press1[i + 1];
	return c % 2;
}
void solve1() {//brutal
	int ans = 30;
	for (int i = 0; i < 1 << 20; i++) {
		for (int j = 0; j < 20; j++) {
			press1[j + 1] = i >> j & 1;
		}
		int c = 0; bool flag = true;
		for (int i = 1; i <= 20; i++) {
			if (press1[i] == 1) {
				c++;
			}
			if (getStat1(i) == 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (c < ans)ans = c;
		}
	}
	printf("%d\n", ans);
}
int main() {
		for (int i = 1; i <= 20; i++) {
			scanf("%d", &map[i]);
		}
		solve1();
}