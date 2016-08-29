/*
Balanced Lineup
Time Limit: 5000MS		Memory Limit: 65536K
Total Submissions: 47363		Accepted: 22241
Case Time Limit: 2000MS
Description

For the daily milking, Farmer John's N cows (1 ≤ N ≤ 50,000) always line up in the same order. One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. However, for all the cows to have fun they should not differ too much in height.

Farmer John has made a list of Q (1 ≤ Q ≤ 200,000) potential groups of cows and their heights (1 ≤ height ≤ 1,000,000). For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.

Input

Line 1: Two space-separated integers, N and Q.
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i
Lines N+2..N+Q+1: Two integers A and B (1 ≤ A ≤ B ≤ N), representing the range of cows from A to B inclusive.
Output

Lines 1..Q: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.
Sample Input

6 3
1
7
3
4
2
5
1 5
4 6
2 2
Sample Output

6
3
0
Source

USACO 2007 January Silver

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <utility>
#include <algorithm>
#define maxN 50050
#define maxH 1000100
int height[maxN];
int N, Q;
typedef std::pair<int, int> node;//min and max height
node dat[maxN*3];
void init(int k,int l,int r) {
	if (r - l == 1) {
		dat[k].first = height[l];
		dat[k].second = height[l];
	}
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		init(chl, l, (l + r) / 2);
		init(chr, (l + r) / 2, r);
		dat[k].first = std::min(dat[chl].first, dat[chr].first);
		dat[k].second = std::max(dat[chl].second, dat[chr].second);
	}
}
//外部调用query(a,b,0,0,n)
node query(int a, int b, int k, int l, int r) {
	if (a == b) {
		return node(0, 0);
	}
	if (r <= a || l >= b)
		return node(maxH, 0);
	if (a <= l && r <= b)
		return dat[k];
	else {
		node n1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		node n2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return node(std::min(n1.first, n2.first), std::max(n1.second, n2.second));
	}
}
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d", &height[i]);
	}
	init(0, 0, N);
	int a, b;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &a, &b);
		node no = query(a-1, b, 0, 0, N);
		printf("%d\n", no.second - no.first);
	}
}