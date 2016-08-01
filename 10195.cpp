/*
 * 10195.cpp
 *
 *  Created on: May 18, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<math.h>
using namespace std;

//const double pi=3.141592653589793238462643383279502884197;
int main() {
	double a, b, c, p, r;

	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
		if (a == 0 || b == 0 || c == 0) {
			printf("The radius of the round table is: 0.000\n");
		} else {
			p = (a + b + c) / 2.0;
			printf("The radius of the round table is: %.3lf\n",
					sqrt((p - a) * (p - b) * (p - c) / p));

		}
	}
}

