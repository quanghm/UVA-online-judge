/*
 * 11152.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<cmath>
const double PI = 2.0 * acos(0);

using namespace std;

int main() {
	double a, b, c, p, ro, ri, s;
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
		p = (a + b + c) / 2.0;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		ri = s / p;
		ri = PI * ri * ri;
		ro = (a * b * c) / (4 * s);
		ro = PI * ro * ro;
		printf("%0.4lf %0.4lf %0.4lf\n", ro - s, s - ri, ri);
	}
}

