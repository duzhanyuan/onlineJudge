/*
Pseudoprime numbers
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8912		Accepted: 3760
Description

Fermat's theorem states that for any prime number p and for any integer a > 1, ap = a (mod p). That is, if we raise a to the pth power and divide by p, the remainder is a. Some (but not very many) non-prime values of p, known as base-a pseudoprimes, have this property for some a. (And some, known as Carmichael Numbers, are base-a pseudoprimes for all a.)

Given 2 < p ¡Ü 1000000000 and 1 < a < p, determine whether or not p is a base-a pseudoprime.

Input

Input contains several test cases followed by a line containing "0 0". Each test case consists of a line containing p and a.

Output

For each test case, output "yes" if p is a base-a pseudoprime; otherwise output "no".

Sample Input

3 2
10 3
341 2
341 3
1105 2
1105 3
0 0
Sample Output

no
no
yes
no
yes
yes
Source

Waterloo Local Contest, 2007.9.23

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
bool isPrime(__int64 n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
__int64 bigMod(__int64 a, __int64 p, __int64 m) {//return a^p mod p
	if (p == 0)return 1;
	__int64 x = bigMod(a, p / 2, m);
	__int64 ans = x * x % m;
	if (p % 2 == 1)ans = ans * a % m;
	return ans;
}
int main() {
	__int64 p, a;
	while (true) {
		scanf("%I64d %I64d", &p, &a);
		if (p == 0 && a == 0)break;
		if (isPrime(p)) {
			printf("no\n");
		}
		else {
			if (a == bigMod(a, p, p)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
	return 0;
}