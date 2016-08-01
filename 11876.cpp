/*
 * uva11876.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: Quang Hoang
 */
#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int M = 1001;
bool a[M] = { 0 }; // if i is check
vector<int> primes;
int nod(int i) {
	int r = 1, s = 0;
	//int d = 2;
	if (i == 1)
		return 1;
	for (vector<int>::iterator it = primes.begin();
			it != primes.end() && *it < i; it++)
		if (i % *it == 0) {
			s = 1;
			while (i % *it == 0) {
				i /= *it;
				s++;
			}
			r *= s;
		}
	if (i > 1) {
		r *= 2;
	}
	return r;
}

int main() {
	int n = 32;

	for (int i = 2; i < n; i++) {
		if (!a[i])
			for (int j = i * i; j < M; j += i) { // kill multiple of i
				a[j] = true;
			}
	}

	primes.push_back(2);
	for (int i = 3; i < M; i += 2) {
		if (!a[i]) {
			primes.push_back(i);
		}
	}

	int no[1000001] = { };
	int j = 1, i = 1;
	no[1] = 1;
	while (1) {
		i += nod(i);
		while (j < i && j < 1000001) {
			no[j + 1] = no[j];
			j++;
		} //now j=i;
		if (i < 1000001) {
			no[i] = no[i - 1] + 1;
		} else
			break;
	}

	cin >> n;
	int a, b;
	for (int c = 1; c <= n; c++) {
		cin >> a >> b;
		printf("Case %d: %d\n", c, no[b] - no[a - 1]);
	}
	return 0;
}
