/*
 *10209.cpp
 *
 *Createdon:May17,2015
 *Author:quanghoang
 */
#include<cstdio>

const double pi = 3.141592653589793238462643383279502884197;//1693993751058209;
const double s3 = 1.732050807568877293527446341505872366942;//8052538103806280;

using namespace std;

int main() {
	double x;
	double rb=(s3*2+pi/3.0-4.0);
	double rc=(4-s3-2.0*pi/3.0);
	double a, b, c;
	while (scanf("%lf", &x) != EOF) {
		x *= x;
		b = rb * x;
		c = rc * x;
		a = x - b - c;

		printf("%.3lf %.3lf %.3lf\n", a, b, c);
	}
}

