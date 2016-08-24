/*
Human Gene Functions
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 19023		Accepted: 10601
Description

It is well known that a human gene can be considered as a sequence, consisting of four nucleotides, which are simply denoted by four letters, A, C, G, and T. Biologists have been interested in identifying human genes and determining their functions, because these can be used to diagnose human diseases and to design new drugs for them.

A human gene can be identified through a series of time-consuming biological experiments, often with the help of computer programs. Once a sequence of a gene is obtained, the next job is to determine its function.
One of the methods for biologists to use in determining the function of a new gene sequence that they have just identified is to search a database with the new gene as a query. The database to be searched stores many gene sequences and their functions – many researchers have been submitting their genes and functions to the database and the database is freely accessible through the Internet.

A database search will return a list of gene sequences from the database that are similar to the query gene.
Biologists assume that sequence similarity often implies functional similarity. So, the function of the new gene might be one of the functions that the genes from the list have. To exactly determine which one is the right one another series of biological experiments will be needed.

Your job is to make a program that compares two genes and determines their similarity as explained below. Your program may be used as a part of the database search if you can provide an efficient one.
Given two genes AGTGATG and GTTAG, how similar are they? One of the methods to measure the similarity
of two genes is called alignment. In an alignment, spaces are inserted, if necessary, in appropriate positions of
the genes to make them equally long and score the resulting genes according to a scoring matrix.

For example, one space is inserted into AGTGATG to result in AGTGAT-G, and three spaces are inserted into GTTAG to result in –GT--TAG. A space is denoted by a minus sign (-). The two genes are now of equal
length. These two strings are aligned:

AGTGAT-G
-GT--TAG

In this alignment, there are four matches, namely, G in the second position, T in the third, T in the sixth, and G in the eighth. Each pair of aligned characters is assigned a score according to the following scoring matrix.


denotes that a space-space match is not allowed. The score of the alignment above is (-3)+5+5+(-2)+(-3)+5+(-3)+5=9.

Of course, many other alignments are possible. One is shown below (a different number of spaces are inserted into different positions):

AGTGATG
-GTTA-G

This alignment gives a score of (-3)+5+5+(-2)+5+(-1) +5=14. So, this one is better than the previous one. As a matter of fact, this one is optimal since no other alignment can have a higher score. So, it is said that the
similarity of the two genes is 14.
Input

The input consists of T test cases. The number of test cases ) (T is given in the first line of the input file. Each test case consists of two lines: each line contains an integer, the length of a gene, followed by a gene sequence. The length of each gene sequence is at least one and does not exceed 100.
Output

The output should print the similarity of each test case, one per line.
Sample Input

2
7 AGTGATG
5 GTTAG
7 AGCTATT
9 AGCTTTAAA
Sample Output

14
21
Source

Taejon 2001

*/
#define _CRT_SECURE_NO_WARNINGS
#define maxN 100
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int value(char a, char b) {
	if (( a =='A' && b == 'C') || (a == 'C' && b == 'A')) {
		return -1;
	}
	if ((a == 'A'  && b == 'G') || (a == 'G' && b == 'A')) {
		return -2;
	}
	if ((a == 'A'  && b == 'T') || (a == 'T'&&b == 'A')) {
		return -1;
	}
	if ((a == 'A'  && b == '-') || (a == '-'&&b == 'A')) {
		return -3;
	}
	if ((a == 'G'  && b == 'C') || (a == 'C'&&b == 'G')) {
		return -3;
	}
	if ((a == 'T'  && b == 'C') || (a == 'C'&&b == 'T')) {
		return -2;
	}
	if ((a == '-'  && b == 'C') || (a == 'C'&&b == '-')) {
		return -4;
	}
	if ((a == 'T'  && b == 'G') || (a == 'G'&&b == 'T')) {
		return -2;
	}
	if ((a == '-'  && b == 'G') || (a == 'G'&&b == '-')) {
		return -2;
	}
	if ((a == 'T'  && b == '-') || (a == '-'&&b == 'T')) {
		return -1;
	}
	return 0;
}
int main() {
	int dp[maxN + 5][maxN + 5];//dp[i][j]代表a[i-1]b[j-1]的最大相似值
	int t;
	scanf("%d", &t);
	char a[maxN+5], b[maxN+5];
	int n, m;
	while (t--) {
		scanf("%d %s", &n, a);
		scanf("%d %s", &m, b);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] + value(a[i - 1], '-');
		}
		for (int j = 1; j <= m; j++) {
			dp[0][j] = dp[0][j-1] + value(b[j - 1], '-');
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i-1] == b[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 5;
				}
				else {
					dp[i][j] = max(dp[i-1][j-1] + value(a[i-1], b[j-1]), dp[i][j-1] + value('-', b[j-1]));
					dp[i][j] = max(dp[i][j], dp[i-1][j] + value(a[i-1], '-'));
				}

			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}