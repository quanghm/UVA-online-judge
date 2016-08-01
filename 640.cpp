/*
 * 640.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quanghoang
 */
#include<stdio.h>
#include<vector>
using namespace std;

const int N = 1000001;
int main() {
	vector<int> s;	//self numbers
	bool a[N + 1] = { 0 };

	int j = 1, u, d;
	while (j < N) {
		//search for the first none true
		while (j < N && (a[j])) {
			j++;
		}
		// now a[j] == false;
		s.push_back(j);
		u = j;
		while (1) {
			d = u;
			while (d) {
				u += d % 10;
				d /= 10;
			}
			if (u>N){break;}
			if (a[u]) {
				break;
			} else {
				a[u] = true;
			}
		}
		j++;
	}

	for (vector<int>::iterator it = s.begin(); it != s.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}

