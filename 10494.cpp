/*
 * 10494.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string m;
	char op;
	int n;
	while (cin >> m >> op >> n) {
//		bool first=false;
		if (op == 37) {
			long long v = 0;
			for (string::iterator it = m.begin(); it != m.end(); it++) {
				v = (v * 10 + (*it - 48)) % n;
			}
			printf("%lld\n", v);
		} else {
			bool first = false;
			long long v = 0;
			int r = 0;
			for (string::iterator it = m.begin(); it != m.end(); it++) {
				v = v * 10 + (*it - 48);
				r = v / n;
				v = v % n;
				if (r || first) {
					printf("%d", r);
				}
				if (r) { //r=0 and first=false;
					first = true;
				}
			}
			if (!first) {
				printf("0\n");
			} else {
				printf("\n");
			}
		}
	}
}

