/*
 * 438.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<cmath>
using namespace std;
const double pi = 3.141592653589793;

double len(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	double a, b, c, p, s;

	while (scanf("%lf%lf %lf%lf %lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
		a = len(x1, y1, x2, y2);
		b = len(x2, y2, x3, y3);
		c = len(x3, y3, x1, y1);
		p = (a + b + c) / 2;

		s = sqrt(p * (p - a) * (p - b) * (p - c));
		s = (a * b * c)*pi/(s*2.0)+1e-15;
		printf("%.2lf\n",s);
	}
}
