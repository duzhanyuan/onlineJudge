/*
The Embarrassed Cryptographer
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 14002		Accepted: 3820
Description

The young and very promising cryptographer Odd Even has implemented the security module of a large system with thousands of users, which is now in use in his company. The cryptographic keys are created from the product of two primes, and are believed to be secure because there is no known method for factoring such a product effectively.
What Odd Even did not think of, was that both factors in a key should be large, not just their product. It is now possible that some of the users of the system have weak keys. In a desperate attempt not to be fired, Odd Even secretly goes through all the users keys, to check if they are strong enough. He uses his very poweful Atari, and is especially careful when checking his boss' key.
Input

The input consists of no more than 20 test cases. Each test case is a line with the integers 4 <= K <= 10100 and 2 <= L <= 106. K is the key itself, a product of two primes. L is the wanted minimum size of the factors in the key. The input set is terminated by a case where K = 0 and L = 0.
Output

For each number K, if one of its factors are strictly less than the required L, your program should output "BAD p", where p is the smallest factor in K. Otherwise, it should output "GOOD". Cases should be separated by a line-break.
Sample Input

143 10
143 20
667 20
667 30
2573 30
2573 40
0 0
Sample Output

GOOD
BAD 11
GOOD
BAD 23
GOOD
BAD 31
Source
Nordic 2005
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
const int RangeK = 1000100;
const int Base = 100000;//进制
const int Width = 5;
int Prime[RangeK + 1];//全局变量自动置0
int KD[101 / Width + 1];
void PrimeTable() {
	int c = 0;
	Prime[c++] = 2;
	for (int i = 3; i <= RangeK; i += 2) {
		bool flag = true;
		for (int j = 0; Prime[j] * Prime[j] <= i; j++) {//直接拿素数进行判断
			if (!(i%Prime[j])) {
				flag = false;
				break;
			}
		}
		if (flag) { Prime[c++] = i; }
	}
}
bool judge(int len,int p) {
	int ans = 0;
	if (KD[len - 1] == 0) { len--; }
	for (int i = 0; i < len; i++) {
		ans =(int) (((long long)ans*Base+KD[i])%p);
	}
	return ans == 0 ? true : false;
}
int main() {
	PrimeTable();
	char K[101]; int L;
	while (true) {
		scanf("%s %d", K, &L);
		if (strcmp(K,"0")==0 && L == 0) { break; }
		int len = strlen(K);
		int n = len / Width;
		string str(K);
		for (int i = 0; i < n; i++) {
			KD[i] = atoi(str.substr(i*Width,Width).c_str());
		}
		KD[n] = atoi(str.substr(n*Width).c_str());
		//分解
		int pMin = 0; bool flag = false;
		while (Prime[pMin] < L) {
			if (judge(n + 1, Prime[pMin])) {
				flag = true;
				printf("BAD %d\n", Prime[pMin]);
				break;
			}
			pMin++;
		}
		if (!flag) {
			printf("GOOD\n");
		}
	}
}