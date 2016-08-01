/*
 * uva138.cpp
 *
 *  Created on: May 9, 2015
 *      Author: quang
 */
#include<stdio.h>
#include<math.h>
using namespace std;

int main() {
	long m = 2, r, s;
	int t = 10;

	while (t--) {
		while (1) {
			r =  m * (m + 1)/2;
			s = (long) floor(sqrt(r));
			if (s * s == r) {
				printf("%10ld%10ld\n",s,m);
				m++;
				break;
			} else {
				m++;
			}
		}
	}
}

