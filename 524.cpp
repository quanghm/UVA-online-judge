/*
 * 524.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
using namespace std;

bool isPrime(int n) {
	return n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17
			|| n == 19 || n == 23 || n == 29 || n == 31;
}

vector<vector<int> > hp(int b, vector<int> s) {
	vector<vector<int> > r;
	int l = s.size();
	if (l > 1) {
		for (int i = 0; i < l; i++) {
			if (isPrime(b + s[i])) {
				vector<int> u = s;
				u.erase(u.begin() + i);
				vector<vector<int> > ut = hp(s[i], u);
				for (vector<vector<int> >::iterator it = ut.begin();
						it != ut.end(); it++) {
					vector<int> w = *it;
					w.insert(w.begin(), s[i]);
					r.push_back(w);
				}
			}
		}
	} else {
		if (isPrime(b + s[0])) {
			vector<int> w;
//			w.push_back(b);
			w.push_back(s[0]);
			r.push_back(w);
		}
	}
	return r;
}

int main() {
	int n, t = 0;
	while (scanf("%d", &n) != EOF) {
		if (t) {
			printf("\n");
		}
		printf("Case %d:\n", ++t);
		vector<int> s;
		for (int i = 2; i <= n; i++) {
			s.push_back(i);
		}
		vector<vector<int> > r = hp(1, s);
		for (vector<vector<int> >::iterator it = r.begin(); it != r.end();
				it++) {
			if (isPrime(it->back() + 1)) {
				printf("1");
				for (vector<int>::iterator ut = it->begin(); ut != it->end();
						ut++) {
					printf(" %d", *ut);
				}
				printf("\n");
			}
		}
	}
}
