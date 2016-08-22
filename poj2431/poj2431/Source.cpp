/*
Expedition
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 12902		Accepted: 3685
Description

A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.

To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).

The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.
Input

* Line 1: A single integer, N

* Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.

* Line N+2: Two space-separated integers, L and P
Output

* Line 1: A single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.
Sample Input

4
4 4
5 2
11 5
15 10
25 10
Sample Output

2
Hint

INPUT DETAILS:

The truck is 25 units away from the town; the truck has 10 units of fuel. Along the road, there are 4 fuel stops at distances 4, 5, 11, and 15 from the town (so these are initially at distances 21, 20, 14, and 10 from the truck). These fuel stops can supply up to 4, 2, 5, and 10 units of fuel, respectively.

OUTPUT DETAILS:

Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more units, stop to acquire 5 more units of fuel, then drive to the town.
Source

USACO 2005 U S Open Gold
*/
#define _CRT_SECURE_NO_WARNINGS
#define maxN 10000
#include <queue>
#include <cstdio>
using namespace std;
int dtemp[maxN + 2];
int d[maxN + 2];//distance from origin of each fuel stop
int f[maxN + 2];//the amount of fuel of each stop
int N, L, P;
priority_queue<int> past;
struct paira {
	int l; int f;
	
};
bool operator<(paira a, paira b) {
	return a.l < b.l;
}
paira aa[maxN + 2];
void solve() {
	int sum = 0;
	bool able = true;
	for (int i = 1; i <= N + 1; i++) {
		P = P - d[i];
		while (P < 0) {
			if (past.empty()) {
				able = false;
				break;
			}
			P += past.top();
			past.pop();
			sum++;
		}
		if (!able)break;
		past.push(f[i]);
	}

	if(able){
		printf("%d\n", sum);
	}
	else {
		printf("-1\n");
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &aa[i].l, &aa[i].f);
	}
	scanf("%d %d", &L, &P);
	aa[N + 1].l = 0;
	aa[N + 1].f = 0;
	aa[0].l = L;
	sort(aa, aa + N + 1);
	for (int i = 1; i <=N; i++) {
		d[i] = aa[N+1-i].l - aa[N-i].l;
		f[i] = aa[N - i].f;
	}
	d[N + 1] = aa[0].l;
	solve();
	return 0;
}