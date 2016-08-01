/*
 * 11064.cpp
 *
 *  Created on: May 23, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;
const int M = 46341;
int main() {
	bool a[M] = { };
	int n = 216, m,phi, s,t;

	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < M; j += i) {
				a[j] = 1;
			}
		}
	}

	// get list of primes<M;
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i < M; i += 2) {
		if (!a[i]) {
			primes.push_back(i);
		}
	}

	//main program
	while (scanf("%d", &m) != EOF) {
		n=m;
		phi = n;
		s = 1;
		for (vector<int>::iterator it = primes.begin();
				it != primes.end() && *it <= n; it++) {
			if (n % *it == 0) {
				phi /= *it;
				phi *= *it-1;
				t = 1;
				while (n % *it == 0) {
					n /= *it;
					t++;
				}
				s*=t;
			}
		}
		if (n>1){
			phi/=n;
			phi*=n-1;
			s*=2;
		}
		printf("%d\n",m-phi-s+1);
	}
}

