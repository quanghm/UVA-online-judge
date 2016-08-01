/*
 * 11689.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quang
 */
#include <cstdio>
using namespace std;

int main() {
	int n, e, f, c;

	scanf("%d", &n);

	while (n--) {
		scanf("%d%d%d", &e, &f, &c);
		e += f;
		if (e >= c) {
			e /= (c - 1);
			printf("%d\n", e);
		}else{
			printf("0\n");
		}
	}
}

