/*
Median
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 5925		Accepted: 1974
Description

Given N numbers, X1, X2, ... , XN, let us calculate the difference of every pair of numbers: ∣Xi - Xj∣ (1 ≤ i ＜ j ≤ N). We can get C(N,2) differences through this work, and now your task is to find the median of the differences as quickly as you can!

Note in this problem, the median is defined as the (m/2)-th  smallest number if m,the amount of the differences, is even. For example, you have to find the third smallest one in the case of m = 6.

Input

The input consists of several test cases.
In each test case, N will be given in the first line. Then N numbers are given, representing X1, X2, ... , XN, ( Xi ≤ 1,000,000,000  3 ≤ N ≤ 1,00,000 )

Output

For each test case, output the median in a separate line.

Sample Input

4
1 3 2 4
3
1 10 2
Sample Output

1
8
Source

POJ Founder Monthly Contest – 2008.04.13, Lei Tao
*/
//binary search 学习处理差值的技巧

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxN 100050
int X[maxN];
int N, k;
bool able(int n) {// whether n as median is too large
	int c = 0;
	for (int i = 0; i < N; i++) {
		c += N - (std::lower_bound(X, X + N, n + X[i])-X);
	}
	return c > k;
}
int main() {
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &X[i]);
		}
		std::sort(X, X + N);
		k = N*(N - 1) / 4; int mid = 0;
		int l = 0, r = X[N-1]-X[0];
		while (r - l > 1) {
			 mid = (l + r) / 2;
			if (able(mid))l = mid;
			else r = mid;
		}
		printf("%d\n", l);
	}
	return 0;
}
