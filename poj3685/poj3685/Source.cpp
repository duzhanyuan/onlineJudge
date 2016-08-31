/*
Matrix
Time Limit: 6000MS		Memory Limit: 65536K
Total Submissions: 6301		Accepted: 1810
Description

Given a N × N matrix A, whose element in the i-th row and j-th column Aij is an number that equals i2 + 100000 × i + j2 - 100000 × j + i × j, you are to find the M-th smallest element in the matrix.

Input

The first line of input is the number of test case.
For each test case there is only one line contains two integers, N(1 ≤ N ≤ 50,000) and M(1 ≤ M ≤ N × N). There is a blank line before each test case.

Output

For each test case output the answer on a single line.

Sample Input

12

1 1

2 1

2 2

2 3

2 4

3 1

3 2

3 8

3 9

5 1

5 25

5 10
Sample Output

3
-99993
3
12
100007
-199987
-99993
100019
200013
-399969
400031
-99939
Source

POJ Founder Monthly Contest – 2008.08.31, windy7926778

*/
//二分查找
//从左上到右下的对角线从右上往左下递增，在N足够大的情况下不成立
//j一定时，数值随i递增，故枚举每一列，并对每一列进行二分查找
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define maxN 500050
long long N,M;
int T;
long long calc(int i, int j) {
	return (long long)i*i + (long long)100000 * (long long)i + (long long)j*j-(long long) 100000 * j + (long long)i*j;
}
bool able(long long x) {
	long long ans = 0;
	for (int j = 1; j <= N; j++) {
		int l = 0, r = 1+N;
		int mid;
		while (r - l > 1) {
			mid = (l + r) / 2;
			if (x > calc(mid,j))l = mid;
			else r = mid;
		}
		ans += l;
		if (ans >= M)return true;
	}
	return false;
}
int main() {
	scanf("%d",&T);
	while (T--) {
		getchar();
		scanf("%lld %lld", &N, &M);
		long long r = 3 * N*N + N * 100000+1;
		long long l = -N * 100000-1;
		long long mid;
		while (r - l > 1) {
			mid = (l + r) / 2;
			if (able(mid))r = mid;
			else l = mid;
		}
		printf("%lld\n", l);
	}
	
	return 0;
}