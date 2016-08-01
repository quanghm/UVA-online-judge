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
	int a[1001][1001] = { };	// a[i+1][j+1]: matching till s[i] and r[j]

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == r[j]) {
				a[i + 1][j + 1] = a[i][j] + 1;
			} else {
				a[i + 1][j + 1] =
						(a[i][j + 1] > a[i + 1][j]) ? a[i][j + 1] : a[i + 1][j];
			}
		}
	}
	return a[l][m];
}

int main() {
	while (getline(cin, s) && getline(cin, r)) {
		cout << common() << endl;
	}
}

