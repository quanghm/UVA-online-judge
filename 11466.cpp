/*
 * 11466.cpp
 *
 *  Created on: May 27, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;

vector<int> primes;
const long long N = 10000000;

long long lpd(long long n) {
	int flag = 0; // one factor
	int r;
	for (vector<int>::iterator it = primes.begin();
			it != primes.end() && *it <= n; it++) {
		if (n % *it == 0) {
			while (n % *it == 0) {
				n /= *it;
			}
			r = *it;
			flag++;
			if (n == 1) {
				if (flag == 1) {
					return -1;
				} else {
					return r;
				}
			}
		}
	}
	return (flag?n:-1);
}
bool a[N] = { };
int main() {

	long long n = 31622;
	for (long long i = 2; i < n; i++) {
		if (!a[i]) {
			for (long long j = i * i; j < N; j += i) {
				a[j] = 1;
			}
		}
	}
	primes.push_back(2);
	for (int j = 3; j < N; j += 2) {
		if (!a[j]) {
			primes.push_back(j);
		}
	}
	while (scanf("%lld", &n) && n) {
		if (n < 0) {
			n = -n;
		}
		if (n == 1) {
			printf("-1\n");
		} else {
			printf("%lld\n", lpd(n));
		}
	}
}

