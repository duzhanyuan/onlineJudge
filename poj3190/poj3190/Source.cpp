/*
Stall Reservations
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 5474		Accepted: 1974		Special Judge
Description

Oh those picky N (1 <= N <= 50,000) cows! They are so picky that each one will only be milked over some precise time interval A..B (1 <= A <= B <= 1,000,000), which includes both times A and B. Obviously, FJ must create a reservation system to determine which stall each cow can be assigned for her milking time. Of course, no cow will share such a private moment with other cows.

Help FJ by determining:
The minimum number of stalls required in the barn so that each cow can have her private milking period
An assignment of cows to these stalls over time
Many answers are correct for each test dataset; a program will grade your answer.
Input

Line 1: A single integer, N

Lines 2..N+1: Line i+1 describes cow i's milking interval with two space-separated integers.
Output

Line 1: The minimum number of stalls the barn must have.

Lines 2..N+1: Line i+1 describes the stall to which cow i will be assigned for her milking period.
Sample Input

5
1 10
2 4
3 6
5 8
4 7
Sample Output

4
1
2
3
2
4
Hint

Explanation of the sample:

Here's a graphical schedule for this output:

Time     1  2  3  4  5  6  7  8  9 10

Stall 1 c1>>>>>>>>>>>>>>>>>>>>>>>>>>>

Stall 2 .. c2>>>>>> c4>>>>>>>>> .. ..

Stall 3 .. .. c3>>>>>>>>> .. .. .. ..

Stall 4 .. .. .. c5>>>>>>>>> .. .. ..
Other outputs using the same number of stalls are possible.
Source

USACO 2006 February Silver
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define maxN 50050
struct cow {
	int L; int R;
	int id; int stall;
	cow() :L(-1), R(-1), id(-1), stall(-1) {}
	cow(int l, int r, int i, int s) :L(l), R(r), id(i), stall(s) {}
};
bool cmpL(const cow & c1, const cow & c2) {
	return c1.L < c2.L;
}
bool cmpId(const cow & c1, const cow & c2) {
	return c1.id < c2.id;
}
cow cows[maxN];
typedef std::pair<int, int> ss;//end time - stall id
struct qcmp {
	bool operator()(const ss & s1, const ss & s2) {
		return s1.first > s2.first;
	}
};

int main() {
	int N;
	scanf("%d", &N);
	std::priority_queue<ss,std::vector<ss>,qcmp> stall;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &cows[i].L, &cows[i].R);
		cows[i].id = i;
		cows[i].stall = -1;
	}
	int sum = 0;
	std::sort(cows, cows + N, cmpL);
	stall.push(ss(cows[0].R, 1));
	cows[0].stall = ++sum;
	for (int i = 1; i < N; i++) {
		if (cows[i].L > stall.top().first) {
			cows[i].stall = stall.top().second;
			stall.pop();
		}
		else {
			cows[i].stall = ++sum;
		}
		stall.push(ss(cows[i].R, cows[i].stall));
	}
	std::sort(cows, cows + N, cmpId);
	printf("%d\n", sum);
	for (int i = 0; i < N; i++) {
		printf("%d\n", cows[i].stall);
	}
	return 0;
}