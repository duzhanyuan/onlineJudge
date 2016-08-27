/*
Jessica's Reading Problem
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 10745		Accepted: 3585
Description

Jessica's a very lovely girl wooed by lots of boys. Recently she has a problem. The final exam is coming, yet she has spent little time on it. If she wants to pass it, she has to master all ideas included in a very thick text book. The author of that text book, like other authors, is extremely fussy about the ideas, thus some ideas are covered more than once. Jessica think if she managed to read each idea at least once, she can pass the exam. She decides to read only one contiguous part of the book which contains all ideas covered by the entire book. And of course, the sub-book should be as thin as possible.

A very hard-working boy had manually indexed for her each page of Jessica's text-book with what idea each page is about and thus made a big progress for his courtship. Here you come in to save your skin: given the index, help Jessica decide which contiguous part she should read. For convenience, each idea has been coded with an ID, which is a non-negative integer.

Input

The first line of input is an integer P (1 ≤ P ≤ 1000000), which is the number of pages of Jessica's text-book. The second line contains P non-negative integers describing what idea each page is about. The first integer is what the first page is about, the second integer is what the second page is about, and so on. You may assume all integers that appear can fit well in the signed 32-bit integer type.

Output

Output one line: the number of pages of the shortest contiguous part of the book which contains all ideals covered in the book.

Sample Input

5
1 8 8 8 1
Sample Output

2
Source

POJ Monthly--2007.08.05, Jerry

*/
//PCCB ex3.2.1 尺取法例题
//题目情境虐狗。。。。
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <set>
#define maxP 1000010
int a[maxP];
int main() {
	std::set<int> all;//count the number of different ideas
	int P; scanf("%d", &P);
	for (int i = 0; i < P; i++) {
		scanf("%d", &a[i]);
		all.insert(a[i]);
	}
	int n = all.size();
	std::map<int, int> idea;//pair id of the idea and the amount of the idea she has read
	int s = 0, t = 0, res = P,num = 0;
	while (true) {
		while (t < P && num < n) {
			if (idea[a[t++]]++ == 0) {
				num++;
			}
		}
		if (num < n)break;
		if (t - s < res)res = t - s;
		if (--idea[a[s++]]==0) {
			num--;
		}
	}
	printf("%d\n", res);
	return 0;
}