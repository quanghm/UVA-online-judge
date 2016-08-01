/*
 * 10139.cpp
 *
 *  Created on: May 19, 2015
 *      Author: quang
 */
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
const int m = 46343;
int main() {
	int n = 216;
	bool a[m] = { }; // if i is check
	vector<int> primes;
	int i = 1;

	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		for (int j = i * i; j < m; j += i) { // kill multiple of i
			a[j] = true;
		}
	}

	for (i = 2; i < m; i++) {
		if (!a[i]) {
			primes.push_back(i);
		}
	}

	int l, s, t, k;
	bool flag;
	while (scanf("%d%d", &l, &n) != EOF) {
		flag = true;
		printf("%d", n);
		// factorize n;
		for (vector<int>::iterator it = primes.begin();
				it != primes.end() && *it < n; it++) {
			if (n % *it == 0) {
				s = 0;
				t = 0;
				while (n % *it == 0) { // find factor of *it in n
					s++;
					n /= *it;
				}
				k = l;
				while (k > 0) {	// find factor of *it in l!
					k /= *it;
					t += k;
				}
				if (s > t) {
					flag = false;
					break;
				}
			}
		}
		if (n > l && n > 1) {
			flag = false;
		}
		if (flag) {
			printf(" divides %d!\n", l);
		} else {
			printf(" does not divide %d!\n", l);
		}

	}
}
