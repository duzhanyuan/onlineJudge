/*
Best Cow Line
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 19145		Accepted: 5309
Description

FJ is about to take his N (1 ¡Ü N ¡Ü 2,000) cows to the annual"Farmer of the Year" competition. In this contest every farmer arranges his cows in a line and herds them past the judges.

The contest organizers adopted a new registration scheme this year: simply register the initial letter of every cow in the order they will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that order he just registers BSD). After the registration phase ends, every group is judged in increasing lexicographic order according to the string of the initials of the cows' names.

FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible. He decides to rearrange his cows, who have already lined up, before registering them.

FJ marks a location for a new line of the competing cows. He then proceeds to marshal the cows from the old line to the new one by repeatedly sending either the first or last cow in the (remainder of the) original line to the end of the new line. When he's finished, FJ takes his cows for registration in this new order.

Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.

Input

* Line 1: A single integer: N
* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the cow in the ith position in the original line

Output

The least lexicographic string he can make. Every line (except perhaps the last one) contains the initials of 80 cows ('A'..'Z') in the new line.

Sample Input

6
A
C
D
B
C
B
Sample Output

ABCBCD
Source

USACO 2007 November Silver

*/

#include <iostream>
#define maxN 2000
using namespace std;
char A[maxN];char B[maxN];
int n;
void solve(){
	int a = 0; //header
	int b = n - 1 - a;//tailor
	int i = 0;
	while (a <= b) {
		bool left = true;
		for (int i = 0; a + i <= b; i++) {
			if (A[a + i] < A[b - i]) {
				left = true;
				break;
			}
			else if (A[a + i] > A[b - i]) {
				left = false;
				break;
			}
		}
		if (left) B[i]=A[a++];
		else B[i]=A[b--];
		i++;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	solve();
	for (int i = 1; i <= n; i++) {
		cout << B[i-1];
		if (i % 80 == 0)cout << endl;
	}
	cout << endl;
	return 0;
}