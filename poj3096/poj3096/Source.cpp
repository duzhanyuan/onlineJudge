/*
Surprising Strings
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 6802		Accepted: 4410
Description

The D-pairs of a string of letters are the ordered pairs of letters that are distance D from each other. A string is D-unique if all of its D-pairs are different. A string is surprising if it is D-unique for every possible distance D.

Consider the string ZGBG. Its 0-pairs are ZG, GB, and BG. Since these three pairs are all different, ZGBG is 0-unique. Similarly, the 1-pairs of ZGBG are ZB and GG, and since these two pairs are different, ZGBG is 1-unique. Finally, the only 2-pair of ZGBG is ZG, so ZGBG is 2-unique. Thus ZGBG is surprising. (Note that the fact that ZG is both a 0-pair and a 2-pair of ZGBG is irrelevant, because 0 and 2 are different distances.)

Acknowledgement: This problem is inspired by the "Puzzling Adventures" column in the December 2003 issue of Scientific American.

Input

The input consists of one or more nonempty strings of at most 79 uppercase letters, each string on a line by itself, followed by a line containing only an asterisk that signals the end of the input.

Output

For each string of letters, output whether or not it is surprising using the exact output format shown below.

Sample Input

ZGBG
X
EE
AAB
AABA
AABB
BCBABCC
*
Sample Output

ZGBG is surprising.
X is surprising.
EE is surprising.
AAB is surprising.
AABA is surprising.
AABB is NOT surprising.
BCBABCC is NOT surprising.
Source

Mid-Central USA 2006

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define maxS 85
char str[maxS];
bool solve(int len) {
	int d = 1;
	while (d < len) {
		for (int i = 0; i < len - d; i++) {
			for (int j = i + 1; j < len - d; j++) {
				if (str[i] == str[j] && str[i + d] == str[j + d]) {
					return false;
				}
			}
		}
		d++;
	}
	return true;
}
int main() {
	while (true) {
		scanf("%s", str);
		int len = strlen(str);
		if (len == 1 && str[0] == '*') {
			break;
		}
		if (solve(len))printf("%s is surprising.\n", str);
		else printf("%s is NOT surprising.\n", str);
		
	}
	return 0;
}