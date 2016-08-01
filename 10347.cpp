/*
 * 10347.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	double a, b, c;
	double p, s;
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
		p = (a + b + c) / 2.0;

		if (p > a && p > b && p > c) {
			s = sqrt(p * (p - a) * (p - b) * (p - c))*4.0/3.0;
			printf("%.3lf\n", s);
		} else {
			printf("-1.000\n");
		}
	}
}

