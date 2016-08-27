/*
Description

People are different. Some secretly read magazines full of interesting girls' pictures, others create an A-bomb in their cellar, others like using Windows, and some like difficult mathematical games. Latest marketing research shows, that this market segment was so far underestimated and that there is lack of such games. This kind of game was thus included into the KOKOD¨¢KH. The rules follow:

Each player chooses two numbers Ai and Bi and writes them on a slip of paper. Others cannot see the numbers. In a given moment all players show their numbers to the others. The goal is to determine the sum of all expressions AiBi from all players including oneself and determine the remainder after division by a given number M. The winner is the one who first determines the correct result. According to the players' experience it is possible to increase the difficulty by choosing higher numbers.

You should write a program that calculates the result and is able to find out who won the game.

Input

The input consists of Z assignments. The number of them is given by the single positive integer Z appearing on the first line of input. Then the assignements follow. Each assignement begins with line containing an integer M (1 <= M <= 45000). The sum will be divided by this number. Next line contains number of players H (1 <= H <= 45000). Next exactly H lines follow. On each line, there are exactly two numbers Ai and Bi separated by space. Both numbers cannot be equal zero at the same time.
Output

For each assingnement there is the only one line of output. On this line, there is a number, the result of expression
(A1B1+A2B2+ ... +AHBH)mod M.

Sample Input

3
16
4
2 3
3 4
4 5
5 6
36123
1
2374859 3029382
17
1
3 18132
Sample Output

2
13195
13
Source

CTU Open 1999

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int M;
int pow_mod(long long a, long long b) {
	if (b == 0)return 1;
	long long x = pow_mod(a, b / 2);
	long long ans = x* x % M;
	if (b % 2 == 1)ans = ans * a % M;
	return ans;
}
int main() {
	int Z;
	scanf("%d", &Z);
	while (Z--) {
		int H;
		scanf("%d %d", &M, &H);
		int ans = 0;
		long long a, b;
		for (int i = 0; i < H; i++) {
			scanf("%lld %lld", &a, &b);
			ans = (ans + pow_mod(a, b)) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}