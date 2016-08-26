/*
Sunscreen
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 7371		Accepted: 2602
Description

To avoid unsightly burns while tanning, each of the C (1 ≤ C ≤ 2500) cows must cover her hide with sunscreen when they're at the beach. Cow i has a minimum and maximum SPF rating (1 ≤ minSPFi ≤ 1,000; minSPFi ≤ maxSPFi ≤ 1,000) that will work. If the SPF rating is too low, the cow suffers sunburn; if the SPF rating is too high, the cow doesn't tan at all........

The cows have a picnic basket with L (1 ≤ L ≤ 2500) bottles of sunscreen lotion, each bottle i with an SPF rating SPFi (1 ≤ SPFi ≤ 1,000). Lotion bottle i can cover coveri cows with lotion. A cow may lotion from only one bottle.

What is the maximum number of cows that can protect themselves while tanning given the available lotions?

Input

* Line 1: Two space-separated integers: C and L
* Lines 2..C+1: Line i describes cow i's lotion requires with two integers: minSPFi and maxSPFi
* Lines C+2..C+L+1: Line i+C+1 describes a sunscreen lotion bottle i with space-separated integers: SPFi and coveri

Output

A single line with an integer that is the maximum number of cows that can be protected while tanning

Sample Input

3 2
3 10
2 5
1 5
6 2
4 1
Sample Output

2
Source

USACO 2007 November Gold

*/
//贪心 优先队列 需要认真体会
#define _CRT_SECURE_NO_WARNINGS
#define maxC 2501
#define maxL 2501
#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main() {
	P pcow[maxC], plot[maxL];
	priority_queue<int,vector<int>,greater<int> > qcow;
	int C, L, l, h, spf, n;
	scanf("%d %d", &C, &L);
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &pcow[i].first, &pcow[i].second);
	}
	for (int i = 0; i < L; i++) {
		scanf("%d %d", &plot[i].first, &plot[i].second);
	}
	sort(pcow, pcow + C);
	sort(plot, plot + L);
	int ans = 0; int j = 0;
	for (int i = 0; i < L; i++) {
		while (j < C && pcow[j].first <= plot[i].first) {
			qcow.push(pcow[j].second);
			j++;
		}
		while (!qcow.empty() && plot[i].second) {
			int k = qcow.top(); qcow.pop();
			if (plot[i].first <= k) {
				ans++;
				plot[i].second--;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}