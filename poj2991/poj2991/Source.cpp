/*
Crane
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 5729		Accepted: 1557		Special Judge
Description

ACM has bought a new crane (crane -- jeřáb) . The crane consists of n segments of various lengths, connected by flexible joints. The end of the i-th segment is joined to the beginning of the i + 1-th one, for 1 ≤ i < n. The beginning of the first segment is fixed at point with coordinates (0, 0) and its end at point with coordinates (0, w), where w is the length of the first segment. All of the segments lie always in one plane, and the joints allow arbitrary rotation in that plane. After series of unpleasant accidents, it was decided that software that controls the crane must contain a piece of code that constantly checks the position of the end of crane, and stops the crane if a collision should happen.

Your task is to write a part of this software that determines the position of the end of the n-th segment after each command. The state of the crane is determined by the angles between consecutive segments. Initially, all of the angles are straight, i.e., 180o. The operator issues commands that change the angle in exactly one joint.
Input

The input consists of several instances, separated by single empty lines.

The first line of each instance consists of two integers 1 ≤ n ≤10 000 and c 0 separated by a single space -- the number of segments of the crane and the number of commands. The second line consists of n integers l1,..., ln (1 li 100) separated by single spaces. The length of the i-th segment of the crane is li. The following c lines specify the commands of the operator. Each line describing the command consists of two integers s and a (1 ≤ s < n, 0 ≤ a ≤ 359) separated by a single space -- the order to change the angle between the s-th and the s + 1-th segment to a degrees (the angle is measured counterclockwise from the s-th to the s + 1-th segment).
Output

The output for each instance consists of c lines. The i-th of the lines consists of two rational numbers x and y separated by a single space -- the coordinates of the end of the n-th segment after the i-th command, rounded to two digits after the decimal point.

The outputs for each two consecutive instances must be separated by a single empty line.
Sample Input

2 1
10 5
1 90

3 2
5 5 5
1 270
2 90
Sample Output

5.00 10.00

-10.00 5.00
-5.00 10.00
Source

CTU Open 2005
*/
//PCCB ex3.1.1 segment tree
//计算几何和线段树的内容 还需仔细推敲
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#define maxN 10010
#define maxC 20010
const int ST_SIZE = (1 << 15) - 1;
int N, C;
int L[maxN];
int S[maxC], A[maxN];

//segment tree
double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

//currrent angle
double prv[maxN];
void init(int k, int l, int r) {
	//init the segment tree
	//k is the number of the node, l,r represents section [l,r)
	ang[k] = vx[k] = 0.0;
	if (r - l == 1) {
		//leaf node
		vy[k] = L[l];
	}
	else {
		int chl = k * 2 + 1, chr = k * 2 + 2;
		init(chl, l, (l + r) / 2);
		init(chr, (l + r) / 2, r);
		vy[k] = vy[chl] + vy[chr];
	}
}

void change(int s, double a, int v, int l, int r) {
	//change s and s's angle to a
	//v is the number of the node, section [l,r)
	if (s <= l)return;
	else if (s < r) {
		int chl = v * 2 + 1, chr = v * 2 + 2;
		int m = (l + r) / 2;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if (s <= m)ang[v] += a;
		double s = sin(ang[v]), c = cos(ang[v]);
		vx[v] = vx[chl] + (c*vx[chr] - s*vy[chr]);
		vy[v] = vy[chl] + (s*vx[chr] + c*vy[chr]);
	}
}

void solve() {
	init(0, 0, N);
	for (int i = 1; i < N; i++)prv[i] = M_PI;
	for (int i = 0; i < C; i++) {
		int s = S[i];
		double a = A[i] / 360.0 * 2 * M_PI;//turn degree to radian
		change(s, a - prv[s], 0, 0, N);
		prv[s] = a;
		printf("%.2f %.2f\n", vx[0], vy[0]);
	}
}
int main() {
	while (scanf("%d %d", &N, &C) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &L[i]);
		}
		for (int i = 0; i < C; i++) {
			scanf("%d %d", &S[i], &A[i]);
		}
		solve();
		printf("\n");
	}
	
	return 0;
}
