/*
 * 446.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<stack>
#include<string>
using namespace std;

int main() {
	int n;
	int s1, s2, s;
	char c, op;
	scanf("%d", &n);

	while (n--) {
		do {
			c = getchar();
		} while (isspace(c));
		s1 = 0;
		while (c != 32) {
			s1 *= 16;
			s1 += (c > 64) ? (c - 55) : (c - 48);
//			printf("%c,%d\n", c, s1);
			c = getchar();
		}
		op = getchar();
		c = getchar();
		c=getchar();
		s2 = 0;
		while (!isspace(c)) {
			s2 *= 16;
			s2 += (c > 64) ? (c - 55) : (c - 48);
			c = getchar();
		}
		s = (op == 43) ? (s1 + s2) : (s1 - s2);
		stack<bool> bi;

		//binary of s1;
		for (int i = 0; i < 13; i++) {
			bi.push(s1 % 2);
			s1 /= 2;
		}
		for (int i = 0; i < 13; i++) {
			printf("%d", bi.top());
			bi.pop();
		}

		// print operator
		printf(" %c ", op);

		// binary of s2;
		for (int i = 0; i < 13; i++) {
			bi.push(s2 % 2);
			s2 /= 2;
		}
		for (int i = 0; i < 13; i++) {
			printf("%d", bi.top());
			bi.pop();
		}
		printf(" = %d\n", s);
	}
}

