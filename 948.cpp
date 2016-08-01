/*
 * 948.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quang
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> fib;
	fib.push_back(1);
	fib.push_back(1);
	int u = 1, v = 0;
	while (v < 100000000) {
		v = u + (fib.back());
		u = (fib.back());
		fib.push_back(v);
	}
	vector<int>::iterator it;
	cin >> v;
	while (v--)
		while (cin >> u) {
			cout << u << " = ";
			it = fib.begin();
			while (u >= *it) {
				it++;
			}
			it--;
			// now *it>u;
			do{
				cout << 1;
				u -= *it;
				it--;
				while (*it > u && it != fib.begin()) {
					cout << 0;
					it--;
				}
			}while(it!=fib.begin());
			cout << " (fib)\n";
		}

}

