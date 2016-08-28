/*
Dropping tests
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 9884		Accepted: 3447
Description

In a certain course, you take n tests. If you get ai out of bi questions correct on test i, your cumulative average is defined to be

.

Given your test scores and a positive integer k, determine how high you can make your cumulative average if you are allowed to drop any k of your test scores.

Suppose you take 3 tests with scores of 5/5, 0/1, and 2/6. Without dropping any tests, your cumulative average is . However, if you drop the third test, your cumulative average becomes .

Input

The input test file will contain multiple test cases, each containing exactly three lines. The first line contains two integers, 1 ¡Ü n ¡Ü 1000 and 0 ¡Ü k < n. The second line contains n integers indicating ai for all i. The third line contains n positive integers indicating bi for all i. It is guaranteed that 0 ¡Ü ai ¡Ü bi ¡Ü 1, 000, 000, 000. The end-of-file is marked by a test case with n = k = 0 and should not be processed.

Output

For each test case, write a single line with the highest cumulative average possible after dropping k of the given test scores. The average should be rounded to the nearest integer.

Sample Input

3 1
5 0 2
5 1 6
4 2
1 2 7 9
5 6 7 9
0 0
Sample Output

83
100
Hint

To avoid ambiguities due to rounding errors, the judge tests have been constructed so that all answers are at least 0.001 away from a decision boundary (i.e., you can assume that the average is never 83.4997).

Source

Stanford Local 2005
*/
//binary search
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxN 1010
int a[maxN], b[maxN];
int N, K;
bool able(double aver) {//is he able to achieve aver average by dropping k tests
	double c[maxN];
	for (int i = 0; i < N; i++) {
		c[i] = 100 *(double)a[i] - (double)b[i] * aver;
	}
	std::sort(c, c + N);
	double ans = 0;
	for (int i = K; i < N; i++) {
		ans += c[i];
	}
	return ans >= 0;
}
int main() {
	while (true) {
		scanf("%d %d", &N, &K);
		if (N == 0 && K == 0)break;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &b[i]);
		}
		double l = 0, r = 101;
		for(int i=0;i<100;i++) {
			double mid = (l + r) / 2;
			if (able(mid))l = mid;
			else r = mid;
		}
		printf("%d\n",(int)floor(l+0.5));
	}
	return 0;
}