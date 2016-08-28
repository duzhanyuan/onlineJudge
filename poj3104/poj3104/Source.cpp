/*
Drying
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 13700		Accepted: 3525
Description

It is very hard to wash and especially to dry clothes in winter. But Jane is a very smart girl. She is not afraid of this boring process. Jane has decided to use a radiator to make drying faster. But the radiator is small, so it can hold only one thing at a time.

Jane wants to perform drying in the minimal possible time. She asked you to write a program that will calculate the minimal time for a given set of clothes.

There are n clothes Jane has just washed. Each of them took ai water during washing. Every minute the amount of water contained in each thing decreases by one (of course, only if the thing is not completely dry yet). When amount of water contained becomes zero the cloth becomes dry and is ready to be packed.

Every minute Jane can select one thing to dry on the radiator. The radiator is very hot, so the amount of water in this thing decreases by k this minute (but not less than zero ¡ª if the thing contains less than k water, the resulting amount of water will be zero).

The task is to minimize the total time of drying by means of using the radiator effectively. The drying process ends when all the clothes are dry.

Input

The first line contains a single integer n (1 ¡Ü n ¡Ü 100 000). The second line contains ai separated by spaces (1 ¡Ü ai ¡Ü 109). The third line contains k (1 ¡Ü k ¡Ü 109).

Output

Output a single integer ¡ª the minimal possible number of minutes required to dry all clothes.

Sample Input

sample input #1
3
2 3 9
5

sample input #2
3
2 3 6
5
Sample Output

sample output #1
3

sample output #2
2
Source

Northeastern Europe 2005, Northern Subregion
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#define maxN 100050
#define maxA 1000000000
int N, K;
long long a[maxN];
bool able(long long t) {//is she able to dry all the clothes in t minutes
	long long ans = 0;
	if (K == 1) {
		for (int i = 0; i < N; i++) {
			if (a[i] - t > 0) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (a[i] - t > 0) {
				ans += ceil((double)(a[i] - t) / (double)(K - 1));
			}
		}
		return ans <= t;
	}
	
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &K);
	long long l = 0, r = maxA + 5;
	while (r - l > 1) {
		long long mid = (l + r) / 2;
		if (able(mid))r = mid;
		else l = mid;
	}
	if (able(l))printf("%lld\n", l);
	else printf("%lld\n", r);
	return 0;
}