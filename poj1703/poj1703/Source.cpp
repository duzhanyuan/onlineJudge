/*
Find them, Catch them
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 41689		Accepted: 12828
Description

The police office in Tadu City decides to say ends to the chaos, as launch actions to root up the TWO gangs in the city, Gang Dragon and Gang Snake. However, the police first needs to identify which gang a criminal belongs to. The present question is, given two criminals; do they belong to a same clan? You must give your judgment based on incomplete information. (Since the gangsters are always acting secretly.)

Assume N (N <= 10^5) criminals are currently in Tadu City, numbered from 1 to N. And of course, at least one of them belongs to Gang Dragon, and the same for Gang Snake. You will be given M (M <= 10^5) messages in sequence, which are in the following two kinds:

1. D [a] [b]
where [a] and [b] are the numbers of two criminals, and they belong to different gangs.

2. A [a] [b]
where [a] and [b] are the numbers of two criminals. This requires you to decide whether a and b belong to a same gang.
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. Each test case begins with a line with two integers N and M, followed by M lines each containing one message as described above.
Output

For each message "A [a] [b]" in each case, your program should give the judgment based on the information got before. The answers might be one of "In the same gang.", "In different gangs." and "Not sure yet."
Sample Input

1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4
Sample Output

Not sure yet.
In different gangs.
In the same gang.
Source

POJ Monthly--2004.07.18

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define maxN 100000
using namespace std;
int par[maxN*2 + 1];
int rank[maxN*2 + 1];
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x]=find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] == rank[y])rank[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, n;
		scanf("%d %d", &n, &m);
		init(2*n + 1);
		char c[20]; int a; int b;
		for (int i = 1; i <= m; i++) {
			scanf("%s %d %d", &c, &a, &b);
			if (n == 2) {
				if (c[0] == 'A') {
					printf("In different gangs.\n");
				}
			}
			else {
				if (c[0] == 'D') {
					unite(a, b + n);
					unite(b, a + n);
				}
				else {
					if (same(a, b + n) && same(b, a + n)) {
						printf("In different gangs.\n");
					}
					else if (same(a, b) && same(a + n, b + n)) {
						printf("In the same gang.\n");
					}
					else {
						printf("Not sure yet.\n");
					}
				}
			}
		}
	
	}
	return 0;
}