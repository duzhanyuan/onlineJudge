/*
River Hopscotch
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 11790		Accepted: 5069
Description

Every year the cows hold an event featuring a peculiar version of hopscotch that involves carefully jumping from rock to rock in a river. The excitement takes place on a long, straight river with a rock at the start and another rock at the end, L units away from the start (1 ¡Ü L ¡Ü 1,000,000,000). Along the river between the starting and ending rocks, N (0 ¡Ü N ¡Ü 50,000) more rocks appear, each at an integral distance Di from the start (0 < Di < L).

To play the game, each cow in turn starts at the starting rock and tries to reach the finish at the ending rock, jumping only from rock to rock. Of course, less agile cows never make it to the final rock, ending up instead in the river.

Farmer John is proud of his cows and watches this event each year. But as time goes by, he tires of watching the timid cows of the other farmers limp across the short distances between rocks placed too closely together. He plans to remove several rocks in order to increase the shortest distance a cow will have to jump to reach the end. He knows he cannot remove the starting and ending rocks, but he calculates that he has enough resources to remove up to M rocks (0 ¡Ü M ¡Ü N).

FJ wants to know exactly how much he can increase the shortest distance *before* he starts removing the rocks. Help Farmer John determine the greatest possible shortest distance a cow has to jump after removing the optimal set of M rocks.

Input

Line 1: Three space-separated integers: L, N, and M
Lines 2..N+1: Each line contains a single integer indicating how far some rock is away from the starting rock. No two rocks share the same position.
Output

Line 1: A single integer that is the maximum of the shortest distance a cow has to jump after removing M rocks
Sample Input

25 5 2
2
14
11
21
17
Sample Output

4
Hint

Before removing any rocks, the shortest jump was a jump of 2 from 0 (the start) to 2. After removing the rocks at 2 and 14, the shortest required jump is a jump of 4 (from 17 to 21 or from 21 to 25).
Source

USACO 2006 December Silver

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxN 50050
#define maxL 1000000010
int a[maxN];
int N, M,L;
bool able(int d) {//min distance is b,is it able to remove no more than M rocks?
	int last = 0;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i] - a[last] < d) {
			ans++;
		}
		else {
			last = i;
		}
	}
	return ans <= M ;
}
int main() {
	a[0] = 0;
	scanf("%d %d %d", &L, &N, &M);
	int ans = L;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		if (a[i] - a[i - 1] < ans)ans = a[i] - a[i - 1];
	}
	a[N + 1] = L;
	std::sort(a, a + N + 1);
	int l = ans, r = L + 1 ;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (able(mid))l = mid;
		else r = mid;
	}
	printf("%d\n", l);
	return 0;
}