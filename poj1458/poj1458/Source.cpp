/*
Common Subsequence
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 48071		Accepted: 19813
Description

A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = < x1, x2, ..., xm > another sequence Z = < z1, z2, ..., zk > is a subsequence of X if there exists a strictly increasing sequence < i1, i2, ..., ik > of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = < a, b, f, c > is a subsequence of X = < a, b, c, f, b, c > with index sequence < 1, 2, 4, 6 >. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
Input

The program input is from the std input. Each data set in the input contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.
Output

For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
Sample Input

abcfbc         abfcab
programming    contest
abcd           mnp
Sample Output

4
2
0
Source

Southeastern Europe 2003

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxN 1000
using namespace std;
int dp[maxN + 1][maxN + 1];
int main() {
	char stra[maxN]; char strb[maxN];
	while(scanf("%s %s", &stra, &strb)!=EOF){
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < strlen(stra); i++) {
		for (int j = 0; j < strlen(strb); j++) {
			if (stra[i] == strb[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	printf("%d\n", dp[strlen(stra)][strlen(strb)]);
	}
	return 0;
}