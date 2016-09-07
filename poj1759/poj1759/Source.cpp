/*
Garland
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 1955		Accepted: 818
Description

The New Year garland consists of N lamps attached to a common wire that hangs down on the ends to which outermost lamps are affixed. The wire sags under the weight of lamp in a particular way: each lamp is hanging at the height that is 1 millimeter lower than the average height of the two adjacent lamps.

The leftmost lamp in hanging at the height of A millimeters above the ground. You have to determine the lowest height B of the rightmost lamp so that no lamp in the garland lies on the ground though some of them may touch the ground.

You shall neglect the lamp's size in this problem. By numbering the lamps with integers from 1 to N and denoting the ith lamp height in millimeters as Hi we derive the following equations:

H1 = A
Hi = (Hi-1 + Hi+1)/2 - 1, for all 1 < i < N
HN = B
Hi >= 0, for all 1 <= i <= N

The sample garland with 8 lamps that is shown on the picture has A = 15 and B = 9.75.
Input

The input file consists of a single line with two numbers N and A separated by a space. N (3 <= N <= 1000) is an integer representing the number of lamps in the garland, A (10 <= A <= 1000) is a real number representing the height of the leftmost lamp above the ground in millimeters.
Output

Write to the output file the single real number B accurate to two digits to the right of the decimal point representing the lowest possible height of the rightmost lamp.
Sample Input

692 532.81
Sample Output

446113.34
Source

Northeastern Europe 2000
*/
//ÊýÁÐÌâ Hi+1 - Hi = Hi - Hi-1 + 2
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <cmath>
int N; double A;
bool able(double B) {
	double H0 = (N*N + A*N - N - B) / (N - 1);
	double a1 = A - H0;
	int n0 = (int)ceil((1 - a1) / 2);
	if (n0<=1 || n0>=N) {
		return true;
	}
	else {
		double y0 = n0*n0 + (a1 - 1)*n0 + H0;
		double y1=1, y2=1;
		int n1 = n0 - 1;
		if (1 <= n1 && n1 <= N) {
			y1 = n1*n1 + (a1 - 1)*n1 + H0;
		}
		int n2 = n0 + 1;
		if (1 <= n2 && n2 <= N) {
			y2 = n2*n2 + (a1 - 1)*n2 + H0;
		}
		return (y0>=0) && (y1>=0) && (y2 >= 0);
	}
}

int main() {
	scanf("%d %lf", &N, &A);
	double l = 0, r = INT_MAX;
	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if (able(mid))r = mid;
		else l = mid;
	}
	printf("%.2f\n", l);
 
	return 0;
}