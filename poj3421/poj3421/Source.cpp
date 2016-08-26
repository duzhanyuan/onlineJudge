/*
X-factor Chains
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 6565		Accepted: 2048
Description

Given a positive integer X, an X-factor chain of length m is a sequence of integers,

1 = X0, X1, X2, …, Xm = X

satisfying

Xi < Xi+1 and Xi | Xi+1 where a | b means a perfectly divides into b.

Now we are interested in the maximum length of X-factor chains and the number of chains of such length.

Input

The input consists of several test cases. Each contains a positive integer X (X ≤ 220).

Output

For each test case, output the maximum length and the number of such X-factors chains.

Sample Input

2
3
4
10
100
Sample Output

1 1
1 1
2 1
2 2
4 6
Source

POJ Monthly--2007.10.06, ailyanlu@zsu

*/
//排列组合题 设X=p0^a0 * p1^a1 * ``` *pn ^ an
//则length=a0+a1+a2+```+an num=(a0+a1+```+an)!/a0!*a1!*````*an!
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int pnum[100];
void primeFac(int n) {
	memset(pnum, 0, sizeof(pnum));
	int id = 0; bool flag = false;
	for (int i = 2; i*i <= n; i++) {
		flag = false;
		while (n%i == 0) {
			flag = true;
			pnum[id]++;
			n /= i;
		}
		if (flag)id++;
	}
	if (n != 1)pnum[id] = 1;
}
long long fact(int n) {//返回阶乘
	long long ans = 1;
	for (int i = n; i > 0; i--) {
		ans *= i;
	}
	return ans;
}
int main() {
	int n = 0;
	int len = 0;
	long long num = 0;
	while (scanf("%d", &n) != EOF) {
		len = 0; num = 0;
		primeFac(n);
		for (int i = 0; pnum[i] != 0; i++) {
			len += pnum[i];
		}
		num = fact(len);
		for (int i = 0; pnum[i] != 0; i++) {
			num/=fact(pnum[i]);
		}
		printf("%d %d\n", len, num);
	}
	return 0;
}