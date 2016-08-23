/*
Alignment
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 16045		Accepted: 5244
Description

In the army, a platoon is composed by n soldiers. During the morning inspection, the soldiers are aligned in a straight line in front of the captain. The captain is not satisfied with the way his soldiers are aligned; it is true that the soldiers are aligned in order by their code number: 1 , 2 , 3 , . . . , n , but they are not aligned by their height. The captain asks some soldiers to get out of the line, as the soldiers that remain in the line, without changing their places, but getting closer, to form a new line, where each soldier can see by looking lengthwise the line at least one of the line's extremity (left or right). A soldier see an extremity if there isn't any soldiers with a higher or equal height than his height between him and that extremity.

Write a program that, knowing the height of each soldier, determines the minimum number of soldiers which have to get out of line.
Input

On the first line of the input is written the number of the soldiers n. On the second line is written a series of n floating numbers with at most 5 digits precision and separated by a space character. The k-th number from this line represents the height of the soldier who has the code k (1 <= k <= n).

There are some restrictions:
•	2 <= n <= 1000
•	the height are floating numbers from the interval [0.5, 2.5]
Output

The only line of output will contain the number of the soldiers who have to get out of the line.
Sample Input

8
1.86 1.86 1.30621 2 1.4 1 1.97 2.2
Sample Output

4
Source

Romania OI 2002
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define maxN 1000
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int h[maxN+1];
	float temp;
	int dp[maxN + 1];//以h[i]结尾的最长上升子序列
	int dp1[maxN + 1];//以h[i]开头的最长下降子序列
	for (int i = 0; i < n; i++) {
		scanf("%f", &temp);
		h[i] = temp * 100000;
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (h[j] < h[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
	}
	for (int i = n-1; i >=0; i--) {
		dp1[i] = 1;
		for (int j = n-1; j > i; j--) {
			if (h[j] < h[i]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}

		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		int j;
		for (int k = i; k < n; k++) {
			if (h[i] == h[k]) {
				j = k;
			}
		}
		if (i == j) {
			if (dp[i] + dp1[j] - 1 > res) {
				res = dp[i] + dp1[j] - 1;
			}
		}
		else {
			if (dp[i] + dp1[j] > res) {
				res = dp[i] + dp1[j];
			}
		}

	}
	printf("%d\n", n - res);
	return 0;
}