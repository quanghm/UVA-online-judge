/*
 * uva10252.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>
#include<algorithm>
#include <string>

using namespace std;

string common(string s, string r) {
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
	string str = "";

	while (l && m) {
		if (s[l - 1] == r[m - 1]) {
			str = s[l - 1]+str;
			l--,m--;
		} else {
			if (a[l][m - 1] > a[l - 1][m]) {
				m--;
			} else {
				l--;
			}
		}
	}
	return str;
}

int main() {
	string s, r;
	while (getline(cin, s) && getline(cin, r)) {
		sort(s.begin(), s.end());
		sort(r.begin(), r.end());
		cout << common(s, r) << "\n";
	}
}

