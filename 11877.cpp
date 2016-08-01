/*
 * uva11877.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: quang
 */

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) {
			return 0;
		}
		cout << n / 2 << endl;
	}
}

