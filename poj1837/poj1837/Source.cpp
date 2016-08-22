/*
Balance
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 13608		Accepted: 8540
Description

Gigel has a strange "balance" and he wants to poise it. Actually, the device is different from any other ordinary balance.
It orders two arms of negligible weight and each arm's length is 15. Some hooks are attached to these arms and Gigel wants to hang up some weights from his collection of G weights (1 <= G <= 20) knowing that these weights have distinct values in the range 1..25. Gigel may droop any weight of any hook but he is forced to use all the weights.
Finally, Gigel managed to balance the device using the experience he gained at the National Olympiad in Informatics. Now he would like to know in how many ways the device can be balanced.

Knowing the repartition of the hooks and the set of the weights write a program that calculates the number of possibilities to balance the device.
It is guaranteed that will exist at least one solution for each test case at the evaluation.
Input

The input has the following structure:
•	the first line contains the number C (2 <= C <= 20) and the number G (2 <= G <= 20);
•	the next line contains C integer numbers (these numbers are also distinct and sorted in ascending order) in the range -15..15 representing the repartition of the hooks; each number represents the position relative to the center of the balance on the X axis (when no weights are attached the device is balanced and lined up to the X axis; the absolute value of the distances represents the distance between the hook and the balance center and the sign of the numbers determines the arm of the balance to which the hook is attached: '-' for the left arm and '+' for the right arm);
•	on the next line there are G natural, distinct and sorted in ascending order numbers in the range 1..25 representing the weights' values.
Output

The output contains the number M representing the number of possibilities to poise the balance.
Sample Input

2 4
-2 3
3 4 5 8
Sample Output

2
Source

Romania OI 2002

*/
//dp[i][j]为使用到第i个砝码，力矩为j时的放法数
//dp[i][j]+=dp[i-1][j-w[i]*len[i]]
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define maxG 20
#define maxC 20
#define bal 7500
int dp[maxG + 1][bal * 2];
using namespace std;
int main() {
	int c, g;
	int len[maxC + 1];
	int w[maxG + 1];
	scanf("%d %d", &c, &g);
	for (int i = 1; i <= c; i++) {
		scanf("%d", &len[i]);
	}
	for (int i = 1; i <= g; i++) {
		scanf("%d", &w[i]);
	}
	memset(dp, 0, sizeof(dp));
	dp[0][bal] = 1;
	for (int i = 1; i <= g; i++) {
		for (int j = 0; j <= 2 * bal; j++) {
			for (int k = 1; k <= c; k++) {
				dp[i][j+len[k]*w[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%d", dp[g][bal]);
	return 0;
}