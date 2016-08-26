/*
Wireless Network
Time Limit: 10000MS		Memory Limit: 65536K
Total Submissions: 23926		Accepted: 9971
Description

An earthquake takes place in Southeast Asia. The ACM (Asia Cooperated Medical team) have set up a wireless network with the lap computers, but an unexpected aftershock attacked, all computers in the network were all broken. The computers are repaired one by one, and the network gradually began to work again. Because of the hardware restricts, each computer can only directly communicate with the computers that are not farther than d meters from it. But every computer can be regarded as the intermediary of the communication between two other computers, that is to say computer A and computer B can communicate if computer A and computer B can communicate directly or there is a computer C that can communicate with both A and B.

In the process of repairing the network, workers can take two kinds of operations at every moment, repairing a computer, or testing if two computers can communicate. Your job is to answer all the testing operations.
Input

The first line contains two integers N and d (1 <= N <= 1001, 0 <= d <= 20000). Here N is the number of computers, which are numbered from 1 to N, and D is the maximum distance two computers can communicate directly. In the next N lines, each contains two integers xi, yi (0 <= xi, yi <= 10000), which is the coordinate of N computers. From the (N+1)-th line to the end of input, there are operations, which are carried out one by one. Each line contains an operation in one of following two formats:
1.	"O p" (1 <= p <= N), which means repairing computer p.
2.	"S p q" (1 <= p, q <= N), which means testing whether computer p and q can communicate.

The input will not exceed 300000 lines.
Output

For each Testing operation, print "SUCCESS" if the two computers can communicate, or "FAIL" if not.
Sample Input

4 1
0 1
0 2
0 3
0 4
O 1
O 2
O 4
S 1 4
O 3
S 1 4
Sample Output

FAIL
SUCCESS
Source

POJ Monthly,HQM

*/
#define _CRT_SECURE_NO_WARNINGS
#define maxN 1010
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;
struct pc{
	int x;
	int y;
	bool repair;
};
int par[maxN];
int ran[maxN];
int in[maxN][maxN];//in[i]记录与i在d之内的节点
pc map[maxN];
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		ran[i] = 0;
	}
}
int find(int x) {
	if (x == par[x]) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (ran[x] < ran[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (ran[x] == ran[y])ran[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int N;long long d;
	scanf("%d %lld", &N, &d);
	d *= d;
	init(N+5);
	int num;
	memset(in, -1, sizeof(in));
	for (int i = 1; i <= N; i++) {
		scanf("%lld %lld", &map[i].x, &map[i].y);
		map[i].repair = false;
	}
	for (int i = 1; i <= N; i++) {
		num = 0;
		for (int j = 1; j <= N; j++) {
			if ((i != j) && ((map[i].x - map[j].x)*(map[i].x - map[j].x)
				+ (map[i].y - map[j].y)*(map[i].y - map[j].y)
				<= d)) {
				in[i][num++] = j;
			}
		}
	}
	char cmd[10]; int m,n;
	int gg;
	while (scanf("%s", cmd) != EOF) {
		if (cmd[0] == 'O') {
			scanf("%d", &m);
			map[m].repair = true;
			for (int i = 0; (gg = in[m][i]) != -1; i++) {
				if(map[gg].repair){
					unite(m,gg);
				}
			}
		}
		else {
			scanf("%d %d", &m, &n);
			same(m, n) ? printf("SUCCESS\n") : printf("FAIL\n");
		}
	}
}