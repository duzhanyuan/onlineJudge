/*

Cable master
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 38232		Accepted: 8155
Description

Inhabitants of the Wonderland have decided to hold a regional programming contest. The Judging Committee has volunteered and has promised to organize the most honest contest ever. It was decided to connect computers for the contestants using a "star" topology - i.e. connect them all to a single central hub. To organize a truly honest contest, the Head of the Judging Committee has decreed to place all contestants evenly around the hub on an equal distance from it.
To buy network cables, the Judging Committee has contacted a local network solutions provider with a request to sell for them a specified number of cables with equal lengths. The Judging Committee wants the cables to be as long as possible to sit contestants as far from each other as possible.
The Cable Master of the company was assigned to the task. He knows the length of each cable in the stock up to a centimeter,and he can cut them with a centimeter precision being told the length of the pieces he must cut. However, this time, the length is not known and the Cable Master is completely puzzled.
You are to help the Cable Master, by writing a program that will determine the maximal possible length of a cable piece that can be cut from the cables in the stock, to get the specified number of pieces.
Input

The first line of the input file contains two integer numb ers N and K, separated by a space. N (1 = N = 10000) is the number of cables in the stock, and K (1 = K = 10000) is the number of requested pieces. The first line is followed by N lines with one number per line, that specify the length of each cable in the stock in meters. All cables are at least 1 meter and at most 100 kilometers in length. All lengths in the input file are written with a centimeter precision, with exactly two digits after a decimal point.
Output

Write to the output file the maximal length (in meters) of the pieces that Cable Master may cut from the cables in the stock to get the requested number of pieces. The number must be written with a centimeter precision, with exactly two digits after a decimal point.
If it is not possible to cut the requested number of pieces each one being at least one centimeter long, then the output file must contain the single number "0.00" (without quotes).
Sample Input

4 11
8.02
7.43
4.57
5.39
Sample Output

2.00
Source

Northeastern Europe 2001
*/
//PCCB ex3.1.2 二分法求最大最小值
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#define maxN 10010
#define INF 200010
double a[maxN];
int N, K;

bool able(double x) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += floor(a[i] / x);
	}
	return ans >= K;
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &a[i]);
	}
	double l = 0, r = INF;
	double mid;
	for (int i = 0; i <= 100; i++) {//可以double eps=1e-5
		mid = (l + r) / 2;
		if (able(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf("%.2f\n",floor(r*100)/100);
	
	return 0;
}