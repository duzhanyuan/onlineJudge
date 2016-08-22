/*
Coins
Time Limit: 3000MS		Memory Limit: 30000K
Total Submissions: 34784		Accepted: 11818
Description

People in Silverland use coins.They have coins of value A1,A2,A3...An Silverland dollar.One day Tony opened his money-box and found there were some coins.He decided to buy a very nice watch in a nearby shop. He wanted to pay the exact price(without change) and he known the price would not more than m.But he didn't know the exact price of the watch.
You are to write a program which reads n,m,A1,A2,A3...An and C1,C2,C3...Cn corresponding to the number of Tony's coins of value A1,A2,A3...An then calculate how many prices(form 1 to m) Tony can pay use these coins.
Input

The input contains several test cases. The first line of each test case contains two integers n(1<=n<=100),m(m<=100000).The second line contains 2n integers, denoting A1,A2,A3...An,C1,C2,C3...Cn (1<=Ai<=100000,1<=Ci<=1000). The last test case is followed by two zeros.
Output

For each test case output the answer on a single line.
Sample Input

3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
Sample Output

8
4
Source

LouTiancheng@POJ

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define maxN 100
#define maxM 100000
using namespace std;
int dp[maxM + 1];
int a[maxN + 1];
int c[maxN + 1];
int n, m;
void solve() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[j] >= 0) {
				dp[j] = c[i];
			}
			else if (j < a[i] || dp[j - a[i]] <= 0) {
				dp[j] = -1;
			}
			else {
				dp[j] = dp[j - a[i]] - 1;
			}

		}
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		if (dp[i] >= 0) {
			sum++;
		}
	}
	printf("%d\n", sum);
}
int main() {
	while(true){
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
		}
		solve();
	}
	return 0;
}