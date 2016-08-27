/*
Face The Right Way
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 4210		Accepted: 1939
Description

Farmer John has arranged his N (1 ≤ N ≤ 5,000) cows in a row and many of them are facing forward, like good cows. Some of them are facing backward, though, and he needs them all to face forward to make his life perfect.

Fortunately, FJ recently bought an automatic cow turning machine. Since he purchased the discount model, it must be irrevocably preset to turn K (1 ≤ K ≤ N) cows at once, and it can only turn cows that are all standing next to each other in line. Each time the machine is used, it reverses the facing direction of a contiguous group of K cows in the line (one cannot use it on fewer than K cows, e.g., at the either end of the line of cows). Each cow remains in the same *location* as before, but ends up facing the *opposite direction*. A cow that starts out facing forward will be turned backward by the machine and vice-versa.

Because FJ must pick a single, never-changing value of K, please help him determine the minimum value of K that minimizes the number of operations required by the machine to make all the cows face forward. Also determine M, the minimum number of machine operations required to get all the cows facing forward using that value of K.

Input

Line 1: A single integer: N
Lines 2..N+1: Line i+1 contains a single character, F or B, indicating whether cow i is facing forward or backward.
Output

Line 1: Two space-separated integers: K and M
Sample Input

7
B
B
F
B
F
B
B
Sample Output

3 3
Hint

For K = 3, the machine must be operated three times: turn cows (1,2,3), (3,4,5), and finally (5,6,7)
Source

USACO 2007 March Gold

*/
//PCCB ex3.2.2 反转问题(开关问题) 值得学习
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define maxN 5010
int dir[maxN];//direction of each cow,B:1 F:0
int f[maxN];//if interval [i,i+K-1] has turned,f[i]=1;otherwise f[i] = 0
int N;//num of cows
int calM(int k) {//if fails, return -1
	int sum = 0;//the sum of f[j] j = i+1-K+1 to i
	int res = 0;
	memset(f, 0, sizeof(f));
	for (int i = 0; i + k <= N; i++) {
		if ((sum + dir[i]) % 2 != 0) {//now sum = sumof(f[j],j=i-K+1 to i-1)
			//cow i is back
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - k + 1 >= 0) {
			sum -= f[i - k+1];
		}
	}

	//now check whether the remaining cows face front
	for (int i = N - k + 1; i < N; i++) {
		if ((sum + dir[i]) % 2 != 0) {
			return -1;
		}
		if (i - k + 1 >= 0) {
			sum -= f[i - k + 1];
		}
	}
	return res;
}
int main() {
	scanf("%d", &N);
	char c;
	for (int i = 0; i < N; i++) {
		scanf(" %c", &c);
		if (c == 'B')dir[i] = 1;
		else dir[i] = 0;
	}
	int M = N;
	int K = 0;
	for (int k = 1; k <= N; k++) {
		int m = calM(k);
		if (m > 0 && M > m) {
			M = m;
			K = k;
		}
	}
	printf("%d %d\n", K, M);
}