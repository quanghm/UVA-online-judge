/*
 * 10991.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<cmath>
using namespace std;
//#define PI 3.1415926
int main() {
	int n;
	double r1, r2, r3, a, b, c, r, alpha;

	scanf("%d", &n);
	while (n--) {
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		a = r2 + r3, b = r3 + r1, c = r1 + r2;
		r = sqrt((r1 + r2 + r3) * r1 * r2 * r3);
//		printf("s=%0.6lf---\n",r);
		alpha = acos((a * a + b * b - c * c) / (2.0 * a * b));
//		printf("%0.6lf--\n", alpha / PI);
		r -= r3 * r3 * alpha/2.0;
		alpha = acos((b * b + c * c - a * a) / (2.0 * b * c));
		r -= r1 * r1 * alpha/2.0;
		alpha = acos((c * c + a * a - b * b) / (2.0 * c * a));
		r -= r2 * r2 * alpha/2.0;

		printf("%.6lf\n", r);
	}
}
