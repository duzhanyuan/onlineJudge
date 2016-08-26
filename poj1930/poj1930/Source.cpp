/*
Dead Fraction
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 2655		Accepted: 861
Description

Mike is frantically scrambling to finish his thesis at the last minute. He needs to assemble all his research notes into vaguely coherent form in the next 3 days. Unfortunately, he notices that he had been extremely sloppy in his calculations. Whenever he needed to perform arithmetic, he just plugged it into a calculator and scribbled down as much of the answer as he felt was relevant. Whenever a repeating fraction was displayed, Mike simply reccorded the first few digits followed by "...". For instance, instead of "1/3" he might have written down "0.3333...". Unfortunately, his results require exact fractions! He doesn't have time to redo every calculation, so he needs you to write a program (and FAST!) to automatically deduce the original fractions.
To make this tenable, he assumes that the original fraction is always the simplest one that produces the given sequence of digits; by simplest, he means the the one with smallest denominator. Also, he assumes that he did not neglect to write down important digits; no digit from the repeating portion of the decimal expansion was left unrecorded (even if this repeating portion was all zeroes).
Input

There are several test cases. For each test case there is one line of input of the form "0.dddd..." where dddd is a string of 1 to 9 digits, not all zero. A line containing 0 follows the last case.
Output

For each case, output the original fraction.
Sample Input

0.2...
0.20...
0.474612399...
0
Sample Output

2/9
1/5
1186531/2500000
Hint

Note that an exact decimal fraction has two repeating expansions (e.g. 1/5 = 0.2000... = 0.19999...).
Source

Waterloo local 2003.09.27
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
long long gcd(long long a, long long b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
long long mypow(int a, int n) {
	if (n == 0)return 1;
	long long ans = a;
	for (int i = 0; i < n-1; i++) {
		ans *= a;
	}
	return ans;
}

int main() {
	int len = 0;
	long long minDe = 0;
	long long mole = 0;
	while (true) {
		char str[15]; minDe = mole = len = 0;
		scanf("%s", str);
		if (str[1] == '\0') {
			if (str[0] == '0') {
				break;
			}
			else {
				printf("%c/%c\n", str[0], str[0]);
				continue;
			}
		}

		for (len = 0; str[len] != '.' || str[len + 1] != '.'; len++);//0.37... len=4

		bool flag = false;//处理0.0000...的特例
		for (int i = 2; i < len; i++) {
			if (str[i] != '0') {
				flag = true;
				break;
			}
		}
		if (!flag) {
			printf("0/1\n");
			continue;
		}
		if (len == 3) {//0.x....的特例
			int a = str[2] - 48;
			int b = 9;
			int gc = gcd(a, b);
			a = a / gc; b = b / gc;
			printf("%d/%d\n", a, b);
			continue;
		}
		//正常情况
		for (int i = 1; i <= len - 2; i++) {//i循环部分长度
			int loop = 0;//循环部分
			for (int j = i - 1; j >= 0; j--) {
				loop = loop * 10 + str[len - 1 - j] - 48;
			}
			int re = 0;//前缀部分
			int relen = len - i - 2;
			for (int j = 2; j <= relen+1; j++) {
				re = re * 10 + str[j] - 48;
			}
			long long a = loop*mypow(10, relen) + re*(mypow(10, i+relen) - mypow(10, relen));
			long long b = 0;
		//	if(relen!=0){
				b = mypow(10, i + 2 * relen) - mypow(10, 2 * relen);
		//	}
		//	else {
		//		b = mypow(10, i);
		//	}
			long long gc = gcd(a, b);
			a = a / gc; b = b / gc;
			if (minDe == 0 || b < minDe) {
				minDe = b;
				mole = a;
			}
		}
		printf("%lld/%lld\n", mole, minDe);

	}
	return 0;
}