/*
 * 10668.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<cmath>
using namespace std;
const double PI2 = asin(1);
int main() {
	double l, n, c, lc, lo, hi, mid;
	while (scanf("%lf %lf %lf", &l, &n, &c) != EOF && (l >= 0)) {
		if (n == 0 || c == 0||l==0) {
			printf("0.000\n");
		} else {
			c = 1 + n * c;
			lc = l * c;
			hi = PI2;
			lo = 0;

			do {
				mid = (hi + lo) / 2.0;
				n = mid / sin(mid);
				if (n > c) {
					hi = mid;
				} else if (n < c) {
					lo = mid;
				} else {
					break;
				}
			} while (hi - lo > 1e-14);
//			printf("c=%lf; f=%lf--\n", c, n);
			printf("%.3lf\n", (1 - cos(mid)) * 0.5 * lc / mid);
		}
	}
}

