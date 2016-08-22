/*
Longest Ordered Subsequence
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 47346		Accepted: 21054
Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
Sample Input
7
1 7 3 5 9 4 8

Sample Output

4
Source

Northeastern Europe 2002, Far-Eastern Subregion

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxN 1000
using namespace std;
int n;
int a[maxN + 1];
int dp[maxN+1];
void solve(){//O(n^2)
	int res = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	printf("%d\n", res);

}
void solve2() {
	fill(dp, dp + n+1, INT_MAX);
	for (int i = 1; i <= n; i++) {
		*lower_bound(dp, dp + n, a[i]) = a[i];
	}
	printf("%d\n", lower_bound(dp, dp + n, INT_MAX)-dp);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	solve2();
	return 0;
}