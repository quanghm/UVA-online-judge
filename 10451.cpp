/*
 * 10451.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<cmath>

using namespace std;
const double PI = 2 * acos(0);
int main() {
	int c = 0;
	double n, a, r, so, si;
	while (scanf("%lf %lf", &n, &a) != EOF && n > 2) {
		r = 2.0 * a / (n * sin(2 * PI / n));
		so = PI*r;
		r=cos(PI/n);
		si = so*(r*r);
		printf("Case %d: %.5lf %.5lf\n",++c,so-a,a-si);
	}
}

