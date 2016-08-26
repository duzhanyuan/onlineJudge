/*
Sumsets
Time Limit: 2000MS		Memory Limit: 200000K
Total Submissions: 16852		Accepted: 6665
Description

Farmer John commanded his cows to search for different sets of numbers that sum to a given number. The cows use only numbers that are an integer power of 2. Here are the possible sets of numbers that sum to 7:

1) 1+1+1+1+1+1+1
2) 1+1+1+1+1+2
3) 1+1+1+2+2
4) 1+1+1+4
5) 1+2+2+2
6) 1+2+4

Help FJ count all possible representations for a given integer N (1 <= N <= 1,000,000).
Input

A single line with a single integer, N.
Output

The number of ways to represent N as the indicated sum. Due to the potential huge size of this number, print only last 9 digits (in base 10 representation).
Sample Input

7
Sample Output

6
Source

USACO 2005 January Silver
*/
//num[n]:若n为奇数，则dp[n]=dp[n-1]
//若n为偶数，则分情况有两个1或没有1 dp[n]=dp[n-2]+dp[n/2]
#include <iostream>
using namespace std;
#define maxN 1000010
#define M 1000000000
int num[maxN];
int main() {
	int n;
	cin >> n;
	num[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			num[i] = num[i - 1] % M;
		}
		else {
			num[i] = (num[i - 2] + num[i / 2]) % M;
		}
	}
	printf("%d\n", num[n]);
	return 0;
}