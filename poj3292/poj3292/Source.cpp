/*
Semi-prime H-numbers
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8800		Accepted: 3869
Description
This problem is based on an exercise of David Hilbert, who pedagogically suggested that one study the theory of 4n+1 numbers. Here, we do only a bit of that.

An H-number is a positive number which is one more than a multiple of four: 1, 5, 9, 13, 17, 21,... are the H-numbers. For this problem we pretend that these are the only numbers. The H-numbers are closed under multiplication.

As with regular integers, we partition the H-numbers into units, H-primes, and H-composites. 1 is the only unit. An H-number h is H-prime if it is not the unit, and is the product of two H-numbers in only one way: 1 ¡Á h. The rest of the numbers are H-composite.

For examples, the first few H-composites are: 5 ¡Á 5 = 25, 5 ¡Á 9 = 45, 5 ¡Á 13 = 65, 9 ¡Á 9 = 81, 5 ¡Á 17 = 85.

Your task is to count the number of H-semi-primes. An H-semi-prime is an H-number which is the product of exactly two H-primes. The two H-primes may be equal or different. In the example above, all five numbers are H-semi-primes. 125 = 5 ¡Á 5 ¡Á 5 is not an H-semi-prime, because it's the product of three H-primes.

Input

Each line of input contains an H-number ¡Ü 1,000,001. The last line of input contains 0 and this line should not be processed.

Output

For each inputted H-number h, print a line stating h and the number of H-semi-primes between 1 and h inclusive, separated by one space in the format shown in the sample.

Sample Input

21
85
789
0
Sample Output

21 0
85 5
789 62
Source

Waterloo Local Contest, 2006.9.30

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int maxh = 1000100;
int HPrimeNum[maxh];
int HSPrimeNum[maxh];
void PrimeTable() {
	//at begin, assume all h-num are h-primes
	for (int i = 5; i < maxh; i += 4) {
		for (int j = 5; j < maxh; j += 4) {
			long long multi = i*j;
			if (multi > maxh) { break; }
			if (!HPrimeNum[i] && !HPrimeNum[j]) {
				HPrimeNum[multi] = -1;//i j are h-prime,so i*j are semi-prime
			}
			else { HPrimeNum[multi] = -2; }
		}
	}
	int cnt = 0;
	for (int i = 1; i < maxh; i++) {
		if (HPrimeNum[i] == -1) {
			cnt++;
		}
		HSPrimeNum[i] = cnt;
	}
}
int main() {
	int h;
	PrimeTable();
		while(true){
			cin >> h;
			if (!h) { break; }
			cout << h<<" "<<HSPrimeNum[h] << endl;
		}
	return 0;
}