/*
 * uva414.cpp
 *
 *  Created on: May 8, 2015
 *      Author: qhoang
 */
#include<iostream>
using namespace std;

int main() {
	int n, c;
	string s1, s2;

	int l, s = 0, min = 0;

	while ((cin >> n) && (n)) {
		s = 0;
		min = 25;
		c = n;
		while (c--) {
			cin >> s1;
			if ((l=s1.length()) == 25) {
				min = 0;
				getline(cin, s2);
			} else {
				cin >> s2;
				l = 25 - l - s2.length(); //space before merge
				s += l;	//total space
				if (l < min) {
					min = l;	//min space -- to be 0 after merge.
				}
			}
		}
		s -= (min * n);
		cout << s << "\n";
	}
}
