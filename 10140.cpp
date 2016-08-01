/*
 * 10140.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quang
 */
#include<iostream>
#include<vector>
using namespace std;
vector<int> p;
bool isPrime(int n) {
	for (vector<int>::iterator it = p.begin(); it != p.end() && *it * *it <= n;
			it++) {
		if (n % *it == 0) {
			return false;
		}
	}
	return n > 1;
}
int main() {
	const int m = 46340;
	int n = 215;
	bool a[m] = { }; // if i is check

	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < m; j += i) {
				a[j] = 1;
			}
		}
	}
	p.push_back(2);
	for (int i = 3; i < m; i += 2) {
		if (!a[i]) {
			p.push_back(i);
		}
	}

	int l, u, num;
	while (cin >> l >> u) {
		vector<int> b;
		for (int i=l;i<=u;i++){
			b.push_back(i);
		}
		for (vector<int>::iterator it = p.begin(); it != p.end(); it++) {
		}
	}
}

