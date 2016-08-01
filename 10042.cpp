/*
 * 10042.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quang
 */
#include <iostream>
#include<vector>

using namespace std;
int digits(int n) {
	int s = 0;

	while (n) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	const int m = 31625;
	int n = 180;
	bool a[m] = { }; // if i is check
	vector<int> p;
	int i = 1, s, d, l,c;
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
			p.push_back(i);
		}
	}

	vector<int>::iterator it;

	bool flag = true;

	cin>>c;
	while (c--) {
		cin >> l;
		for (n = l+1; n < 1000000200; n++) {
			flag = true;
			it = p.begin();
			s = digits(n);
			i = n;
			while (it != p.end() && i > 1) { // decomposition
				while (it != p.end() && i % *it && *it < i) {
					it++;
				}
				if (it == p.end())
					break;
				if (*it == n) {
					flag = false;
					break;
				}
				d = *it;
				while (i % d == false) {
					s -= digits(d);
					i /= d;
				}
			}
			if (i != n) {
				if (i > 1) {
					s -= digits(i);
				}
				if (s == 0 && flag) {
					cout << n << endl;
					break;
				}
			}
		}
	}
}
