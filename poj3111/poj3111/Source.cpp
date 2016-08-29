/*
K Best
Time Limit: 8000MS		Memory Limit: 65536K
Total Submissions: 8852		Accepted: 2287
Case Time Limit: 2000MS		Special Judge
Description

Demy has n jewels. Each of her jewels has some value vi and weight wi.

Since her husband John got broke after recent financial crises, Demy has decided to sell some jewels. She has decided that she would keep k best jewels for herself. She decided to keep such jewels that their specific value is as large as possible. That is, denote the specific value of some set of jewels S = {i1, i2, ¡­, ik} as

.

Demy would like to select such k jewels that their specific value is maximal possible. Help her to do so.

Input

The first line of the input file contains n ¡ª the number of jewels Demy got, and k ¡ª the number of jewels she would like to keep (1 ¡Ü k ¡Ü n ¡Ü 100 000).

The following n lines contain two integer numbers each ¡ª vi and wi (0 ¡Ü vi ¡Ü 106, 1 ¡Ü wi ¡Ü 106, both the sum of all vi and the sum of all wi do not exceed 107).

Output

Output k numbers ¡ª the numbers of jewels Demy must keep. If there are several solutions, output any one.

Sample Input

3 2
1 1
1 2
1 3
Sample Output

1 2
Source

Northeastern Europe 2005, Northern Subregion
*/
//binary search
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <utility>
#include <algorithm>
#define maxN 1000010
typedef std::pair<int, int> jew;
jew j[maxN];//value and weight
int N, K;
typedef std::pair<double, int> kkl;
kkl seq[maxN];//v - a*w and id
int res[maxN];
bool able(double a) {
	for (int i = 0; i < N; i++) {
		seq[i].first = (double)j[i].first - a*(double)j[i].second;
		seq[i].second = i;
	}
	sort(seq, seq + N);
	double sum = 0;
	for (int i = N - K; i < N; i++) {
		sum += seq[i].first;
	}
	return sum >= 0;
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &j[i].first, &j[i].second);
	}
	double l = 0, r = 10000000;
	for (int i = 0; i < 50; i++) {
		double mid = (l + r) / 2;
		if (able(mid))l = mid;
		else r = mid;
	}
	for (int i = 0; i < K; i++) {
		res[i] = seq[N - K + i].second+1;
	}
	std::sort(res, res + K);
	for (int i = 0; i < K; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}