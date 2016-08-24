/*
Smallest Difference
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8391		Accepted: 2305
Description

Given a number of distinct decimal digits, you can form one integer by choosing a non-empty subset of these digits and writing them in some order. The remaining digits can be written down in some order to form a second integer. Unless the resulting integer is 0, the integer may not start with the digit 0.
For example, if you are given the digits 0, 1, 2, 4, 6 and 7, you can write the pair of integers 10 and 2467. Of course, there are many ways to form such pairs of integers: 210 and 764, 204 and 176, etc. The absolute value of the difference between the integers in the last pair is 28, and it turns out that no other pair formed by the rules above can achieve a smaller difference.
Input

The first line of input contains the number of cases to follow. For each case, there is one line of input containing at least two but no more than 10 decimal digits. (The decimal digits are 0, 1, ..., 9.) No digit appears more than once in one line of the input. The digits will appear in increasing order, separated by exactly one blank space.
Output

For each test case, write on a single line the smallest absolute difference of two integers that can be written from the given digits as described by the rules above.
Sample Input

1
0 1 2 4 6 7
Sample Output

28
Source

Rocky Mountain 2005

*/
//读入一行数量不定的数字
//next_permutation的枚举

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T,num,big,small;
	int a[10];
	cin>>T;
	getchar();
	while (T--) {
		num = big = small = 0;
		char temp[25];
		gets_s(temp);
		for (int i = 0; i < strlen(temp); i++) {
			if ((int)temp[i]-48 >= 0 && (int)temp[i]-48 <= 9)
				a[num++] = (int)temp[i]-48;
		}
		int mini = INT_MAX;
		sort(a, a + num);
		do {
			big = small = 0;
			if (a[0] == 0 || a[num/2]==0 && num > 2)continue;
			for (int i = 0; i < num / 2; i++) {
				big = big * 10 + a[i];
			}
			for (int i = num / 2; i < num; i++) {
				small = small * 10 + a[i];
			}
			mini = min(mini, abs(big - small));
		} while (next_permutation(a, a + num));
		printf("%d\n", mini);
	}
	return 0;
}