/*
 * 10179.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>

using namespace std;

const int M = 316323;

int main() {
	bool a[M] = { };
	vector<int> p;
	int n = 178, phi;

	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < M; j += i) {
				a[j] = 1;
			}
		}
	}
	p.push_back(2);
	for (int i = 3; i < M; i += 2) {
		if (!a[i]) {
			p.push_back(i);
		}
	}

	while (scanf("%d", &n) != EOF && n) {
		//compute phi(n);
		phi = n;
		for (vector<int>::iterator it = p.begin(); it != p.end() && *it <= n;
				it++) {
			if (n % *it == 0) {
				phi /= *it;
				phi *= (*it - 1);
				while (n % *it == 0) {
					n /= *it;
				}
			}
		}
		if (n > 1) {
			phi /= n;
			phi *= n - 1;
		}
		printf("%d\n", phi);
	}
}

