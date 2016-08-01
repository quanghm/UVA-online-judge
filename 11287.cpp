/*
 * 11287.cpp
 *
 *  Created on: May 27, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;
vector<int> primes;

bool isPrime(int p) {
	for (vector<int>::iterator it = primes.begin();
			it != primes.end() && *it < p; it++) {
		if (p % *it == 0 && p != *it) {
			return false;
		}
	}
	return true;
}
int main() {
	int a, p, q;
	bool v[31623] = { };
	for (int i = 2; i < 178; i++) {
		if (!v[i]) {
			for (int j = i * i; j < 31623; j += i) {
				v[j] = 1;
			}
		}
	}
	primes.push_back(2);
	for (int j = 3; j < 31623; j += 2) {
		if (!v[j]) {
			primes.push_back(j);
		}
	}
	long long pow[31];

	// main program
	while (scanf("%d%d", &p, &a) != EOF && p) {
		if (isPrime(p)) {
			printf("no\n");
		} else {
			pow[0] = a;
			//pow[1]=a;
			for (int i = 1; i < 31; i++) {
				pow[i] = (pow[i - 1] * pow[i - 1]) % p;
				//			printf("%lld_________\n",pow[i]);
			}
			int i = 0;
			long long s = 1;
			q = p;
			while (p) {
				if (p % 2) {
					s = (s * pow[i]) % q;
//					printf("%lld::%lld:%d___\n", s, pow[i], i);
				}
				i++;
				p /= 2;
			}
			if (s == a) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		}
	}
}

