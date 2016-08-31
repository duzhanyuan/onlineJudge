/*
Graveyard Design
Time Limit: 10000MS		Memory Limit: 64000K
Total Submissions: 6365		Accepted: 1513
Case Time Limit: 2000MS
Description

King George has recently decided that he would like to have a new design for the royal graveyard. The graveyard must consist of several sections, each of which must be a square of graves. All sections must have different number of graves.
After a consultation with his astrologer, King George decided that the lengths of section sides must be a sequence of successive positive integer numbers. A section with side length s contains s2 graves. George has estimated the total number of graves that will be located on the graveyard and now wants to know all possible graveyard designs satisfying the condition. You were asked to find them.
Input

Input file contains n --- the number of graves to be located in the graveyard (1 <= n <= 1014 ).
Output

On the first line of the output file print k --- the number of possible graveyard designs. Next k lines must contain the descriptions of the graveyards. Each line must start with l --- the number of sections in the corresponding graveyard, followed by l integers --- the lengths of section sides (successive positive integer numbers). Output line's in descending order of l.
Sample Input

2030
Sample Output

2
4 21 22 23 24
3 25 26 27
Source

Northeastern Europe 2004, Northern Subregion
*/
//尺取法，水题
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using std::vector;
typedef std::pair<int, int> p;//length-start
long long N;
bool mycmp(p p1,p p2) {
	return p1.first > p2.first;
}
int main() {
	scanf("%lld", &N);
	vector<p> ans;
	long long l = 1, r = 1;
	int bound = (int)sqrt((double)N);
	long long sum = 0;
	while (true) {
		while (r <= bound && sum < N) {
			sum += r*r;
			r++;
		}
		if (sum < N)break;
		if (sum == N) {
			ans.push_back(p((int)(r - l), (int)l));
			while (l <= r&&sum >= N) {
				sum -= l*l;
				l++;
			}
		}
		while (l <= r&&sum > N) {
			sum -= l*l;
			l++;
		}
		if (sum > N)break;
	}
	std::sort(ans.begin(), ans.end(), mycmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		int len = ans[i].first;
		int l = ans[i].second;
		printf("%d ", len);
		for (int j = 0; j < len; j++) {
			printf("%d ", l + j);
		}
		printf("\n");
	}
}