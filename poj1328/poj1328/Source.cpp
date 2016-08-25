/*
Radar Installation
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 76869		Accepted: 17218
Description

Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d.

We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is above x-axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x-y coordinates.

Figure A Sample Input of Radar Installations


Input

The input consists of several test cases. The first line of each case contains two integers n (1<=n<=1000) and d, where n is the number of islands in the sea and d is the distance of coverage of the radar installation. This is followed by n lines each containing two integers representing the coordinate of the position of each island. Then a blank line follows to separate the cases.

The input is terminated by a line containing pair of zeros
Output

For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. "-1" installation means no solution for that case.
Sample Input

3 2
1 2
-3 1
2 1

1 2
0 2

0 0
Sample Output

Case 1: 2
Case 2: 1
Source

Beijing 2002

*/
//重叠区间问题
#define _CRT_SECURE_NO_WARNINGS
#define maxN 1000
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
class section {
public:
	double l;
	double r;
	section(double left,double right):l(left),r(right){}
	section():l(0),r(0){}
	bool operator<(const section& sec) const {
		if (l < sec.l) {
			return true;
		}
		else if (l == sec.l) {
			return r < sec.r;
		}
		else { return false; }
	}
};
int main() {
	int i = 1;
	int n, d,x,y;
	double c;
	bool flag = true;
	for (;; i++) {
		scanf("%d %d", &n, &d);
		if (n == 0 && d == 0) {
			break;
		}
		flag = true;
		section a[maxN + 1];
		if (d < 0)flag = false;
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &x, &y);
			if(flag){
				if (y <= d) {
					c = (double)sqrt((double)(d*d - y*y));
					a[j] = section((double)x - c, (double)x + c);
				}
				else {
					flag = false;
				}
			}
		}
		if (!flag) {
			printf("Case %d: -1\n",i);
			continue;
		}
		else {
			sort(a, a + n);
			int ans = 0;
			double tmp = a[0].r;
			int sum = 1;
			for (int i = 1; i<n; ++i) {
				if (a[i].l>tmp) {
					tmp = a[i].r;
					sum++;
				}
				else if (a[i].r<tmp) {
					tmp = a[i].r;
				}
			}
			printf("Case %d: %d\n",i, sum);
		}
		


	}
	return 0;
}