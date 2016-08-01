/*
 * 10341.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<cmath>
#define ABS(x) ((x>=0)?x:-x)
using namespace std;
//const double ERR = 1e-20;
//const double nERR = -1e-20;

int p, q, r, s, t, u;
double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; //
}
double df(double x) {
	double c = cos(x);
	return q * c - p * exp(-x) - r * sin(x) + s / (c * c) + 2 * t * x; //
}
int main() {
	double x, v, y;
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if (f(0) == 0.0) {
			printf("0.0000\n");
		} else if (f(1) > 0 || f(0) < 0) {
			printf("No solution\n");
		} else {
			x = 0.5, v = f(x);
			while (ABS(v) > 1e-10 ) {
//				y = x;
				x = x - v / df(x);
				v = f(x);
//				printf("%.4lf %.4lf--\n", x, v);
			}
			printf("%.4lf\n", x);
		}
	}
}

