/*
 * uva1045.cpp
 *
 *  Created on: May 4, 2015
 *      Author: qhoang
 */
#include <iostream>
#include <string>

using namespace std;
string s, r;
int common() {
	int l = s.length();
	int m = r.length();
	int a[l + 1][m + 1] = { };

	int i = 0, j = 0;
	while (i++ < l) {
		j = 0;
		while (j++ < m) {
			if (s[i] == r[j]) {
				a[i + 1, j + 1] = a[i, j] + 1;
			} else {
				a[i + 1, j + 1] =
						(a[i, j + 1] > a[i + 1, j]) ? a[i, j + 1] : a[i + 1, j];
			}
		}
	}
	return a[l + 1][m + 1];
}

int main() {
	while (getline(cin, s) && getline(cin, r)) {
		cout << common() << endl;
	}
}

