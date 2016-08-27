/*
Aggressive cows
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 11320		Accepted: 5556
Description

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input

* Line 1: Two space-separated integers: N and C

* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output

* Line 1: One integer: the largest minimum distance
Sample Input

5 3
1
2
8
4
9
Sample Output

3
Hint

OUTPUT DETAILS:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

Huge input data,scanf is recommended.
Source

USACO 2005 February Gold

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxN 100010
int N, C;
long long a[maxN];
bool able(long long d) {
	int last = 0;
	int crt;
	for (int i = 1; i < C; i++) {
		crt = last + 1;
		while (crt < N && a[crt] - a[last] < d) {
			crt++;
		}
		if (crt == N)return false;
		last = crt;
	}
	return true;
}
int main() {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	std::sort(a, a + N);
	long long l = 0, r = a[N - 1] / C + 10;
	long long mid;
	while (r - l > 1) {
		mid = (l + r) / 2;
		if (able(mid))l = mid;
		else r = mid;
	}
	printf("%d\n", l);
	return 0;
}