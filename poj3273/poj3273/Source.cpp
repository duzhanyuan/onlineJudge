/*
Monthly Expense
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 22779		Accepted: 8919
Description

Farmer John is an astounding accounting wizard and has realized he might run out of money to run the farm. He has already calculated and recorded the exact amount of money (1 ¡Ü moneyi ¡Ü 10,000) that he will need to spend each day over the next N (1 ¡Ü N ¡Ü 100,000) days.

FJ wants to create a budget for a sequential set of exactly M (1 ¡Ü M ¡Ü N) fiscal periods called "fajomonths". Each of these fajomonths contains a set of 1 or more consecutive days. Every day is contained in exactly one fajomonth.

FJ's goal is to arrange the fajomonths so as to minimize the expenses of the fajomonth with the highest spending and thus determine his monthly spending limit.

Input

Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 contains the number of dollars Farmer John spends on the ith day
Output

Line 1: The smallest possible monthly limit Farmer John can afford to live with.
Sample Input

7 5
100
400
300
100
500
101
400
Sample Output

500
Hint

If Farmer John schedules the months so that the first two days are a month, the third and fourth are a month, and the last three are their own months, he spends at most $500 in any month. Any other method of scheduling gives a larger minimum monthly limit.
Source

USACO 2007 March Silver
*/
//¶þ·ÖËÑË÷
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define maxN 100010
#define maxMoney 10010
int M, N;
int a[maxN];
bool able(long long mo) {//is he able to spend at most mo money
	int pre = 0;
	int ans = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++) {

		sum += a[i];
		if (sum > mo) {
			ans++;
			sum = a[i];
		}
	}
	ans++;
	return (ans <= M);
}
int main() {
	scanf("%d %d", &N, &M);
	long long l = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] > l)l = a[i];
	}

	long long r = l*N;
	while (r - l > 1) {
		long long mid = (l + r) / 2;
		if (able(mid))r = mid;
		else l = mid;
	}
	if (able(l)) {
		printf("%lld\n", l);
	}
	else {
		printf("%lld\n", r);

	}
	return 0;
}