/*
 * 11777.cpp
 *
 *  Created on: May 28, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
using namespace std;

int main() {
	int t;
	double m, s;
	priority_queue<double> a;

	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		s = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%lf", &m);
			s += m;
		}
		for (int i = 0; i < 3; i++) {
			scanf("%lf", &m);
			a.push(m);
		}
		m = a.top();
		a.pop();
		m += a.top();
		a.pop();
		a.pop();
		s += m / 2.0;

		if (s >= 90) {
			printf("Case %d: A\n", c);
		} else if (s >= 80) {
			printf("Case %d: B\n", c);
		} else if (s >= 70) {
			printf("Case %d: C\n", c);
		} else if (s >= 60) {
			printf("Case %d: D\n", c);
		} else {
			printf("Case %d: F\n",c);
		}
	}
}

