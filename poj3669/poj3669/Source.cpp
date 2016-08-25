/*
Meteor Shower
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 15885		Accepted: 4186
Description

Bessie hears that an extraordinary meteor shower is coming; reports say that these meteors will crash into earth and destroy anything they hit. Anxious for her safety, she vows to find her way to a safe location (one that is never destroyed by a meteor) . She is currently grazing at the origin in the coordinate plane and wants to move to a new, safer location while avoiding being destroyed by meteors along her way.

The reports say that M meteors (1 ≤ M ≤ 50,000) will strike, with meteor i will striking point (Xi, Yi) (0 ≤ Xi ≤ 300; 0 ≤ Yi ≤ 300) at time Ti (0 ≤ Ti  ≤ 1,000). Each meteor destroys the point that it strikes and also the four rectilinearly adjacent lattice points.

Bessie leaves the origin at time 0 and can travel in the first quadrant and parallel to the axes at the rate of one distance unit per second to any of the (often 4) adjacent rectilinear points that are not yet destroyed by a meteor. She cannot be located on a point at any time greater than or equal to the time it is destroyed).

Determine the minimum time it takes Bessie to get to a safe place.

Input

* Line 1: A single integer: M
* Lines 2..M+1: Line i+1 contains three space-separated integers: Xi, Yi, and Ti

Output

* Line 1: The minimum time it takes Bessie to get to a safe place or -1 if it is impossible.

Sample Input

4
0 0 2
2 1 2
1 1 2
0 3 5
Sample Output

5
Source

USACO 2008 February Silver

*/
//bfs 注意陨石降落范围不等于地图就那么大 mdzz

#define _CRT_SECURE_NO_WARNINGS
#define maxN 300
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;
int map[maxN+3][maxN+3];//-1表示永不击中，否则就记录被击中的时间
int vis[maxN+3][maxN+3];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int time = 0;
int sx = 0, sy = 0;
bool flag = false;
void bfs() {
	queue<P> que;
	que.push(P(sx, sy));
	vis[0][0] = 0;
	while (!que.empty()) {
		P p = que.front(); que.pop();		
		time = vis[p.first][p.second];
		
		if (map[p.first][p.second]==-1) {
			flag = true;
			break;
		}
		/*if (map[p.first][p.second] <= time) {
			flag = false;
			break;
		}*/
		for (int i = 0; i < 4; i++) {
			int x = p.first + dir[i][0];
			int y = p.second + dir[i][1];
			if (0 <= x && x < maxN+3 && 0 <= y && y < maxN+3 && vis[x][y] == -1 && (time + 1 < map[x][y]||map[x][y]==-1)) {
				que.push(P(x, y));
				vis[x][y] = time+1;
			}
		}
	}

}
int main() {
	int m,x0,y0,t,x,y;
	scanf("%d", &m);
	memset(map, -1, sizeof(map));
	memset(vis, -1, sizeof(vis));
	for (int i = 0; i < m; i++) {
		scanf(" %d%d%d", &x0, &y0, &t);
		if (map[x0][y0] == -1 || t < map[x0][y0]) {
			map[x0][y0] = t;
		}
		for (int j = 0; j < 4; j++) {
			x = x0 + dir[j][0];
			y = y0 + dir[j][1];
			if (0 <= x && x <= maxN && 0 <= y && y <= maxN) {
				if (map[x][y] == -1 || t < map[x][y]) {
					map[x][y] = t;
				}
			}
		}
	}		
	bfs();
	if (flag) {
		printf("%d\n", time);
	}
	else {
		printf("-1\n");
	}

	return 0;
}