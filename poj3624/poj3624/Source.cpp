/*
Charm Bracelet
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 34081		Accepted: 15118
Description

Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N (1 ¡Ü N ¡Ü 3,402) available charms. Each charm i in the supplied list has a weight Wi (1 ¡Ü Wi ¡Ü 400), a 'desirability' factor Di (1 ¡Ü Di ¡Ü 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ¡Ü M ¡Ü 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

Output

* Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints

Sample Input
4 6
1 4
2 6
3 12
2 7

Sample Output

23
Source

USACO 2007 December Silver
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxN 3402
#define maxM 12880
using namespace std;
int dp[maxM + 1];
int w[maxN + 1];
int d[maxN + 1];
int N, M;
void solve() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = M; j >=w[i]; j--) {
				dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
		}
	}
	cout << dp[M] << endl;
}
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> d[i];
	}
	solve();
	return 0;
}