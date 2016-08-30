/*
K-th Number
Time Limit: 20000MS		Memory Limit: 65536K
Total Submissions: 49657		Accepted: 16825
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
//method1: bucket method
//Time limit exceed
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define maxN 100050
#define maxM 100050
#define B 1000
int N, M;
int A[maxN];
int num[maxN];
int l[maxM], r[maxM], k[maxM];
int bucket[maxN / B][B+1];
void init() {
	for (int i = 0; i < N; i++) {
		bucket[i / B][i-(i/B)*B]=A[i];
		num[i] = A[i];
	}
	for (int i = 0; i < N / B; i++) {
		std::sort(bucket[i], bucket[i]+B);
	}
	std::sort(num, num + N);//binary search needs that the sequence is sorted
}
void solve() {
	for (int i = 0; i < M; i++) {
		int ul = -1, ur = N + 1;
		while (ur - ul > 1) {
			int c = 0, tl = l[i] - 1, tr = r[i];
			int md = (ul + ur) / 2;
			int t = num[md];
			while (tl < tr && tl%B != 0)if (A[tl++] <= t)c++;
			while (tl < tr && tr%B != 0)if (A[--tr] <= t)c++;
			while (tl < tr) {
				c += std::upper_bound(bucket[tl / B], bucket[tl / B]+B, t) - bucket[tl / B];
				tl += B;
			}
			if (c >= k[i])ur = md;
			else ul = md;
		}
		printf("%d\n", num[ur]);
	}
}
int main() {
	//int T; scanf("%d", &T);
	//while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		init();
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &l[i], &r[i], &k[i]);
		}
		solve();
	//}
	return 0;
}