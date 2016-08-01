/*
 * 386.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quang
 */
#include<stdio.h>

using namespace std;

int main() {
	int a3, b3, c3;
	for (int a = 2; a < 201; a++) {
		a3 = a*a*a;
		for (int b = 2; b < a ; b++) {
			b3 = a3 - b*b*b;
			for (int c = b; c < a ; c++) {
				c3 = b3 - c*c*c;
				for (int d = c; d < a; d++) {
					if (c3 == d*d*d) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					}
				}
			}
		}
	}
}
