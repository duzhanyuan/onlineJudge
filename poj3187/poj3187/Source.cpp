/*
Backward Digit Sums
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 6319		Accepted: 3654
Description

FJ and his cows enjoy playing a mental game. They write down the numbers from 1 to N (1 <= N <= 10) in a certain order and then sum adjacent numbers to produce a new list with one fewer number. They repeat this until only a single number is left. For example, one instance of the game (when N=4) might go like this:

3   1   2   4

4   3   6

7   9

16
Behind FJ's back, the cows have started playing a more difficult game, in which they try to determine the starting sequence from only the final total and the number N. Unfortunately, the game is a bit above FJ's mental arithmetic capabilities.

Write a program to help FJ play the game and keep up with the cows.
Input

Line 1: Two space-separated integers: N and the final sum.
Output

Line 1: An ordering of the integers 1..N that leads to the given sum. If there are multiple solutions, choose the one that is lexicographically least, i.e., that puts smaller numbers first.
Sample Input

4 16
Sample Output

3 1 2 4
Hint

Explanation of the sample:

There are other possible sequences, such as 3 2 1 4, but 3 1 2 4 is the lexicographically smallest.
Source

USACO 2006 February Gold & Silver

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
int num[11];
int a[11][11] = { {1},
				  {1,1},
				  {1,2,1},
			      {1,3,3,1},
			      {1,4,6,4,1},
			      {1,5,10,10,5,1},
			      {1,6,15,20,15,6,1},
			      {1,7,21,35,35,21,7,1},
				  {1,8,28,56,70,56,28,8,1},
				  {1,9,36,84,126,126,84,36,9,1},
				  {1,10,45,120,210,256,210,120,10,1}};
int cal(int n) {
	int ans=0;
	for (int i = 0; i < n; i++) {
		ans += num[i] * a[n-1][i];
	}
	return ans;
}
int main() {
	int n, ans;
	scanf("%d %d", &n, &ans);
	for (int i = 1; i <= n; i++) {
		num[i-1] = i;
	}
	do {
		if (cal(n) == ans) {
			break;
		}
	} while (next_permutation(num, num + n));
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", num[i]);
	}
	printf("%d\n", num[n - 1]);
	return 0;
}