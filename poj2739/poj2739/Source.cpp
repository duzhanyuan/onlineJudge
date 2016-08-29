/*
Sum of Consecutive Prime Numbers
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 23409		Accepted: 12794
Description

Some positive integers can be represented by a sum of one or more consecutive prime numbers. How many such representations does a given positive integer have? For example, the integer 53 has two representations 5 + 7 + 11 + 13 + 17 and 53. The integer 41 has three representations 2+3+5+7+11+13, 11+13+17, and 41. The integer 3 has only one representation, which is 3. The integer 20 has no such representations. Note that summands must be consecutive prime
numbers, so neither 7 + 13 nor 3 + 5 + 5 + 7 is a valid representation for the integer 20.
Your mission is to write a program that reports the number of representations for the given positive integer.
Input

The input is a sequence of positive integers each in a separate line. The integers are between 2 and 10 000, inclusive. The end of the input is indicated by a zero.
Output

The output should be composed of lines each corresponding to an input line except the last zero. An output line includes the number of representations for the input integer as the sum of one or more consecutive prime numbers. No other characters should be inserted in the output.
Sample Input

2
3
17
41
20
666
12
53
0
Sample Output

1
1
2
3
0
0
1
2
Source

Japan 2005

*/
//尺取法 注意细节
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#define maxN 11000
int vis[maxN];
int prime[maxN];
int N, K;
void sieve() {
	int m = (int)sqrt(maxN + 0.5);
	for (int i = 2; i < m; i++) {
		if (!vis[i]) {
			for (int j = i*i; j < maxN; j += i) {
				vis[j] = 1;
			}
		}
	}
}
void proPrime() {
	sieve();
	int c = 0;
	for (int i = 2; i <= maxN; i++) {
		if (!vis[i]) {
			prime[c++] = i;
		}
	}
	N = c;
}
void solve() {
	int ans = 0, sum = 0, l = 0, r = 0;
	while (l < N && r < N) {

		while (r <= N && sum < K) {
			sum += prime[r++];
		}
		if (sum == K) {
			ans++;
			while (l < r && sum >= K) {
				sum -= prime[l++];
			}
		}
		else {
			while (l < r && sum > K) {
				sum -= prime[l++];
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
	proPrime();
	while (true) {
		scanf("%d", &K);
		if (K == 0)break;
		solve();
	}
	return 0;
}