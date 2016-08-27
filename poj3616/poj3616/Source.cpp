/*
Milking Time
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8019		Accepted: 3374
Description

Bessie is such a hard-working cow. In fact, she is so focused on maximizing her productivity that she decides to schedule her next N (1 ≤ N ≤ 1,000,000) hours (conveniently labeled 0..N-1) so that she produces as much milk as possible.

Farmer John has a list of M (1 ≤ M ≤ 1,000) possibly overlapping intervals in which he is available for milking. Each interval i has a starting hour (0 ≤ starting_houri ≤ N), an ending hour (starting_houri < ending_houri ≤ N), and a corresponding efficiency (1 ≤ efficiencyi ≤ 1,000,000) which indicates how many gallons of milk that he can get out of Bessie in that interval. Farmer John starts and stops milking at the beginning of the starting hour and ending hour, respectively. When being milked, Bessie must be milked through an entire interval.

Even Bessie has her limitations, though. After being milked during any interval, she must rest R (1 ≤ R ≤ N) hours before she can start milking again. Given Farmer Johns list of intervals, determine the maximum amount of milk that Bessie can produce in the N hours.

Input

* Line 1: Three space-separated integers: N, M, and R
* Lines 2..M+1: Line i+1 describes FJ's ith milking interval withthree space-separated integers: starting_houri , ending_houri , and efficiencyi

Output

* Line 1: The maximum number of gallons of milk that Bessie can product in the N hours

Sample Input

12 4 2
1 2 8
10 12 19
3 6 24
7 10 31
Sample Output

43
Source

USACO 2007 November Silver
*/
//动态规划练习 两重循环完成状态转移
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxN 1000010
#define maxM 1005
int dp[maxM];
struct P {
	int start;
	int end;
	int effi;
	P():start(maxN+5),end(maxN+5),effi(0){}
	P(int s,int e,int ef):start(s),end(e),effi(ef){}
};
P milk[maxM];
bool comp(const P& p1, const P& p2) {
	return p1.end < p2.end;
}
int main() {
	int N, M, R;
	scanf("%d %d %d", &N, &M, &R);
	int s, e, eff;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &eff);
		milk[i] = P(s, e + R, eff);
	}
	std::sort(milk, milk + M,comp);
	int ans = 0;
	for (int i = 0; i < M; i++) {
		dp[i] = milk[i].effi;
	}
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			if (milk[j].start >= milk[i].end) {
				dp[j] = std::max(dp[j], dp[i] + milk[j].effi);
				if (dp[j] > ans)ans = dp[j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}