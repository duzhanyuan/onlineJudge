/*
ʳ����
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 64296		Accepted: 18892
Description

���������������ද��A,B,C�������ද���ʳ������������Ȥ�Ļ��Ρ�A��B�� B��C��C��A��
����N�������1��N��š�ÿ�����ﶼ��A,B,C�е�һ�֣��������ǲ���֪������������һ�֡�
����������˵������N�����������ɵ�ʳ������ϵ����������
��һ��˵����"1 X Y"����ʾX��Y��ͬ�ࡣ
�ڶ���˵����"2 X Y"����ʾX��Y��
���˶�N���������������˵����һ���һ���˵��K�仰����K�仰�е�����ģ��е��Ǽٵġ���һ�仰������������֮һʱ����仰���Ǽٻ�����������滰��
1��	��ǰ�Ļ���ǰ���ĳЩ��Ļ���ͻ�����Ǽٻ���
2��	��ǰ�Ļ���X��Y��N�󣬾��Ǽٻ���
3��	��ǰ�Ļ���ʾX��X�����Ǽٻ���
��������Ǹ��ݸ�����N��1 <= N <= 50,000����K�仰��0 <= K <= 100,000��������ٻ���������
Input

��һ������������N��K����һ���ո�ָ���
����K��ÿ�������������� D��X��Y������֮����һ���ո����������D��ʾ˵�������ࡣ
��D=1�����ʾX��Y��ͬ�ࡣ
��D=2�����ʾX��Y��
Output

ֻ��һ����������ʾ�ٻ�����Ŀ��
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
	init(N * 3+4);//Ԫ��x,x+N,x+2*N�ֱ����x-A,x-B,x-C
	int ans = 0;
	int d, x, y;
	while (K--) {
		scanf("%d%d%d", &d, &x, &y);
		if (x <= 0 || x > N || y <= 0 || y > N) {
			ans++;
			continue;
		}
		if (d == 1) {//x��y����ͬһ��
			if (same(x, y + N) || same(x, y + 2 * N)) {//x-A y-B/y-C����ͬһ��
				ans++;
			}
			else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + 2 * N, y + 2 * N);
			}
		}
		if (d == 2) {//x��y
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