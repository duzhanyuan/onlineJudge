/*
Bound Found
Time Limit: 5000MS		Memory Limit: 65536K
Total Submissions: 2974		Accepted: 916		Special Judge
Description

Signals of most probably extra-terrestrial origin have been received and digitalized by The Aeronautic and Space Administration (that must be going through a defiant phase: "But I want to use feet, not meters!"). Each signal seems to come in two parts: a sequence of n integer values and a non-negative integer t. We'll not go into details, but researchers found out that a signal encodes two integer values. These can be found as the lower and upper bound of a subrange of the sequence whose absolute value of its sum is closest to t.

You are given the sequence of n integers and the non-negative target t. You are to find a non-empty range of the sequence (i.e. a continuous subsequence) and output its lower index l and its upper index u. The absolute value of the sum of the values of the sequence from the l-th to the u-th element (inclusive) must be at least as close to t as the absolute value of the sum of any other non-empty range.
Input

The input file contains several test cases. Each test case starts with two numbers n and k. Input is terminated by n=k=0. Otherwise, 1<=n<=100000 and there follow n integers with absolute values <=10000 which constitute the sequence. Then follow k queries for this sequence. Each query is a target t with 0<=t<=1000000000.
Output

For each query output 3 numbers on a line: some closest absolute sum and the lower and upper indices of some range where this absolute sum is achieved. Possible indices start with 1 and go up to n.
Sample Input

5 1
-10 -5 0 5 10
3
10 2
-9 8 -7 6 -5 4 -3 2 -1 0
5 11
15 2
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
15 100
0 0
Sample Output

5 4 4
5 2 8
9 1 1
15 1 15
15 1 15
Source

Ulm Local 2001

*/
//尺取法 值得学习
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#define maxN 100010
typedef std::pair<int, int> sumpair;
int N, K, T;
sumpair a[maxN];
void solve() {
	int l = 1, r = 1;
	int ans = 2000000000;
	int bestSum = 0;
	//record the best answer
	int s = 0, e = 1;
	while (s <= N && e <= N) {
		int sum = a[e].first - a[s].first;
		if (abs(sum - T) < ans) {
			ans = abs(sum - T);
			bestSum = sum;
			l = a[s].second;
			r = a[e].second;
		}
		if (sum > T)s++;
		else if (sum < T)e++;
		else break;
		if (s == e)e++;
	}
	if (l > r) {
		int temp = l;l = r; r = temp;
	}
	printf("%d %d %d\n", bestSum,1 + l, r);
}
int main() {
	while (true) {
		scanf("%d %d", &N, &K);
		if (N == 0 && K == 0)break;
		a[0] = sumpair(0, 0); int temp;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &temp);
			a[i] = sumpair(a[i - 1].first + temp, i);
		}
		std::sort(a, a + N + 1);
		for (int i = 0; i < K; i++) {
			scanf("%d", &T);
			solve();
		}
	}
	return 0;
}