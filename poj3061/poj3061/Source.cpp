/*
Subsequence
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 12504		Accepted: 5265
Description

A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.
Input

The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.
Output

For each the case the program has to print the result on separate line of the output file.if no answer, print 0.
Sample Input

2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
Sample Output

2
3
Source

Southeastern Europe 2006
*/
//PCCB ex3.2.1 ³ßÈ¡·¨ÀýÌâ
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxN 100010
int a[maxN];
int main() {
	int T, N, S;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &S);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		int t = 0, s = 0, sum = 0, ans = N+1;
		while (true) {
			while (s < N&&sum < S) {
				sum += a[s++];
			}
			if (sum < S)break;
			if (s - t < ans)ans = s - t;
			sum -= a[t++];
		}
		if (ans > N)ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}