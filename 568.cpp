/*
 * uva568.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 10001;

int main() {
	int mod[N];
	int t, s, u;
	mod[0] = 1;
	for (int i = 1; i < N; i++) {
		s = mod[i - 1];
		u = i;
		while (!(u % 5)) {
			u /= 5;
			s = (s % 2) ? ((s + 5) / 2) : (s / 2);
		}
		t = u % 5;
		mod[i] = (s * t) % 5;
	}
	while (cin >> t) {
		if (t < 2) {
			printf("%5d -> 1\n", t);
		} else
			switch (mod[t]) {
			case 1:
				printf("%5d -> %d\n", t, 6);
				break;
			case 2:
				printf("%5d -> %d\n", t, 2);
				break;
			case 3:
				printf("%5d -> %d\n", t, 8);
				break;
			case 4:
				printf("%5d -> %d\n", t, 4);
				break;
			}
	}
}

