/*
K-th Number
Time Limit: 20000MS		Memory Limit: 65536K
Total Submissions: 49676		Accepted: 16830
Case Time Limit: 2000MS
Description

You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.
That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i...j] segment, if this segment was sorted?"
For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2...5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.
Input

The first line of the input file contains n --- the size of the array, and m --- the number of questions to answer (1 <= n <= 100 000, 1 <= m <= 5 000).
The second line contains n different integer numbers not exceeding 109 by their absolute values --- the array for which the answers should be given.
The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 <= i <= j <= n, 1 <= k <= j - i + 1) and represents the question Q(i, j, k).
Output

For each question output the answer to it --- the k-th number in sorted a[i...j] segment.
Sample Input

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Sample Output

5
6
3
Hint

This problem has huge input,so please use c-style input(scanf,printf),or you may got time limit exceed.
Source

Northeastern Europe 2004, Northern Subregion

*/

//method: segment tree AC
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxN 100050
#define maxM 5050
const int ST_SIZE = (1 << 18) - 1;
int A[maxN], num[maxN], L[maxM], R[maxM], K[maxM];
int N, M;
std::vector<int> dat[ST_SIZE];
void init(int k, int l, int r) {
	if (r - l == 1) {
		dat[k].push_back(A[l]);
	}
	else {
		int chl = k * 2 + 1;
		int chr = k * 2 + 2;
		init(chl, l, (l + r) / 2);
		init(chr, (l + r) / 2, r);
		dat[k].resize(r - l);
		std::merge(dat[chl].begin(), dat[chl].end(), dat[chr].begin(), dat[chr].end(),dat[k].begin());
	}
}
int query(int i,int j,int x,int k,int l,int r) {
	//return the number of numbers which is not more than x in section[i,j)
	if (j <= l || i >= r) {
		return 0;
	}
	else if ( i<=l  &&  r<= j) {
		return std::upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
	}
	else {
		int cl = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
		int cr = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
		return cl + cr;
	}
}
void solve() {
	init(0,0,N);
	std::sort(num, num + N);
	for (int i = 0; i < M; i++) {
		int ul = -1, ur = N;
		int l = L[i]-1, r = R[i], k = K[i];
		while (ur - ul > 1) {
			int mid = (ul + ur) / 2;
			int x = num[mid];
			int c = query(l, r, x, 0, 0, N);
			if (c >= k)ur = mid;
			else ul = mid;
		}
		printf("%d\n", num[ur]);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		num[i] = A[i];
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &L[i], &R[i], &K[i]);
	}
	solve();
	return 0;
}