/*
 * 10551.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string p, m;
	long long b, n;
	long long v;
	while ((cin >> b) && b) {
		(cin >> p >> m);
		n = 0;
		for (string::iterator it = m.begin(); it != m.end(); it++) {
			n = n * b + *it - 48;
		}
		v = 0;
		for (string::iterator it = p.begin(); it != p.end(); it++) {
			v = (v * b + (*it - 48)) % n;
		}
		if (v&&(v > b || b < 10)) {
			stack<int> st;
			while (v) {
				st.push(v % b);
				v /= b;
			}
			while (!st.empty()) {
				printf("%d", st.top());
				st.pop();
			}
			printf("\n");
		} else {
			printf("%lld\n", v);
		}
	}

}
