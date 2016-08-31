/*
Frequent values
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 17419		Accepted: 6293
Description

You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input

The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the
query.

The last test case is followed by a line containing a single 0.

Output

For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Sample Input

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output

1
4
3
Source

Ulm Local 2007

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define maxN 100050
#define maxA 100000
int N;
int a[maxN];

struct node {
	int max;//区间的最长序列
	int lnum, lmax;//左端点数值及左端点最长序列
	int rnum, rmax;//右端点数值及右端点最长序列
	node():max(-1),lnum(-maxA-1),lmax(-1),rnum(-maxA-2),rmax(-1){}
	node(int a,int b,int c,int d,int e):max(a),lnum(b),lmax(c),rnum(d),rmax(e){}
}dat[maxN * 3];
int max3(int a, int b, int c) {
	if (a >= b && a >= c)return a;
	if (b >= a && b >= c)return b;
	if (c >= a && c >= b)return c;
}
int max2(int a, int b) {
	if (a >= b)return a;
	else return b;
}
void init(int k, int l, int r) {
	if (r - l == 1) {
		dat[k].max = 1; dat[k].lmax = 1; dat[k].rmax = 1;
		dat[k].lnum = a[l]; dat[k].rnum = a[l];
	}
	else {
		int chl = k * 2 + 1;
		int chr = k * 2 + 2;
		init(chl, l, (l + r) / 2);
		init(chr, (l + r) / 2, r);
		dat[k].lnum = dat[chl].lnum;
		dat[k].rnum = dat[chr].rnum;
		if (dat[chl].rnum == dat[chr].lnum) {
			int max0 = dat[chl].rmax + dat[chr].lmax;
			dat[k].max = max3(max0, dat[chl].max, dat[chr].max);
			if (dat[chl].lnum == dat[chl].rnum) {
				dat[k].lmax = dat[chl].lmax + dat[chr].lmax;
			}
			else {
				dat[k].lmax = dat[chl].lmax;
			}
			if (dat[chr].lnum == dat[chr].rnum) {
				dat[k].rmax = dat[chr].rmax + dat[chl].rmax;
			}
			else {
				dat[k].rmax = dat[chr].rmax;
			}
		}
		else {
			dat[k].max = max2(dat[chl].max, dat[chr].max);
			dat[k].lmax = dat[chl].lmax;
			dat[k].rmax = dat[chr].rmax;
		}
	}
}
node query(int a,int b,int k,int l,int r) {
	if (a <= l && r <= b) {
		return dat[k];
	}
	if (b <= l || a >= r) {
		return node();
	}
	else {
		node n1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		node n2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		node n;
		n.lnum = n1.lnum;
		n.rnum = n2.rnum;
		if (n1.rnum == n2.lnum) {
			int max0 = n1.rmax + n2.lmax;
			n.max = max3(max0, n1.max, n2.max);
			if (n1.lnum == n1.rnum) {
				n.lmax = n1.lmax + n2.lmax;
			}
			else {
				n.lmax = n1.lmax;
			}
			if (n2.lnum == n2.rnum) {
				n.rmax = n2.rmax + n1.rmax;
			}
			else {
				n.rmax = n2.rmax;
			}
		}
		else {
			n.max = max2(n1.max, n2.max);
			n.lmax = n1.lmax;
			n.rmax = n2.rmax;
		}
		return n;
	}
}
int main() {
	int q;
	while (true) {
		scanf("%d", &N);
		if (N == 0)break;
		scanf("%d", &q);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		init(0, 0, N);
		int l, r;
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &l, &r);
			printf("%d\n",query(l - 1, r, 0, 0, N).max);
		}
	}
	return 0;
}