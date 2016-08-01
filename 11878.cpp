/*
 * uva11878.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: quang
 */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b, l = 1, c, d, r;
	char o1, o2;
	char t[4] = { };
	r = 0;
	while (scanf("%d%c%d%c%s", &a, &o1, &b, &o2, t)!=EOF) {
		if (t[0]!= 0) {
			d = 0;
			c = 0;

			while ((t[d] < 58) && (t[d] > 47)) {
				c *= 10;
				c += t[d] - 48;
				d++;
			}
//			printf("%d%c%d%c%d\n",a,o1,b,o2,c);
			if ((a + b == c && o1 - '+' == 0)
					|| (a - b == c && o1 - '-' == 0)) {
				r++;

			}
		}
	}

    printf("%d\n",r);
}
