/*
C Looooops
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 23971		Accepted: 6637
Description

A Compiler Mystery: We are given a C-language style for loop of type
for (variable = A; variable != B; variable += C)

statement;

I.e., a loop which starts by setting variable to value A and while variable is not equal to B, repeats statement followed by increasing the variable by C. We want to know how many times does the statement get executed for particular values of A, B and C, assuming that all arithmetics is calculated in a k-bit unsigned integer type (with values 0 <= x < 2k) modulo 2k.

Input

The input consists of several instances. Each instance is described by a single line with four integers A, B, C, k separated by a single space. The integer k (1 <= k <= 32) is the number of bits of the control variable of the loop and A, B, C (0 <= A, B, C < 2k) are the parameters of the loop.

The input is finished by a line containing four zeros.
Output

The output consists of several lines corresponding to the instances on the input. The i-th line contains either the number of executions of the statement in the i-th instance (a single integer number) or the word FOREVER if the loop does not terminate.
Sample Input

3 3 2 16
3 7 2 16
7 3 2 16
3 4 2 16
0 0 0 0
Sample Output

0
2
32766
FOREVER
Source

CTU Open 2004

*/
//扩展欧几里得算法 相当于求Cx=B-A的最小整数解
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
void gcd(long long a, long long b, int &d, int &x, int &y) {//ax+by=gcd(a,b)=d
	if (!b) {
		d = a; x = 1; y = 0;
	}
	else {
		gcd(b, a%b, d, y, x); y -= x*(a / b);
	}

}
int main() {
	long long A, B, C, k;
	while (true) {
		scanf("%lld %lld %lld %lld",&A, &B, &C, &k);
		if (A == 0 & B == 0 & C == 0 & k == 0) {
			break;
		}
		int x, y, d;
		gcd(C, ((long long)1 << k), d, x, y);
		if ((B - A) % d != 0) {
			printf("FOREVER\n");
		}
		else {
			long long ans = x*(B - A) / d;
			long long s = ((long long)1 << k) / d;
			ans = (ans%s + s) % s;
			printf("%lld\n", ans);
		}
	}
	return 0;
}