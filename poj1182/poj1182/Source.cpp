/*
食物链
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 64296		Accepted: 18892
Description

动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述：
第一种说法是"1 X Y"，表示X和Y是同类。
第二种说法是"2 X Y"，表示X吃Y。
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
1）	当前的话与前面的某些真的话冲突，就是假话；
2）	当前的话中X或Y比N大，就是假话；
3）	当前的话表示X吃X，就是假话。
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。
Input

第一行是两个整数N和K，以一个空格分隔。
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。
若D=1，则表示X和Y是同类。
若D=2，则表示X吃Y。
Output

只有一个整数，表示假话的数目。
Sample Input

100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
Sample Output

3
Source

Noi 01

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
#define maxN 50000
#define maxK 100000
int par[maxN * 3 + 4];
int rank[maxN * 3 + 4];
int N, K;
//int d[maxK], X[maxK], Y[maxK];
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
		return par[x] = find(par[x]);
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
	int N, K;
	scanf("%d %d", &N, &K);
	init(N * 3+4);//元素x,x+N,x+2*N分别代表x-A,x-B,x-C
	int ans = 0;
	int d, x, y;
	while (K--) {
		scanf("%d%d%d", &d, &x, &y);
		if (x <= 0 || x > N || y <= 0 || y > N) {
			ans++;
			continue;
		}
		if (d == 1) {//x和y属于同一类
			if (same(x, y + N) || same(x, y + 2 * N)) {//x-A y-B/y-C属于同一类
				ans++;
			}
			else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + 2 * N, y + 2 * N);
			}
		}
		if (d == 2) {//x吃y
			if (same(x, y) || same(x, y + 2 * N)) {
				ans++;
			}
			else {
				unite(x, y + N);
				unite(x + N, y + 2 * N);
				unite(x + 2 * N, y);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}