/*
 * uva11462.cpp
 *
 *  Created on: May 6, 2015
 *      Author: qhoang
 */
#include <iostream>
using namespace std;
int main() {
	std::cout.sync_with_stdio(false);
	int n, m, t;

	while ((cin >> n) && (n)) {
		int a[100] = { };
		t = n;
		while (t--) {
			cin >> m;
			a[m]++;
		}

		t = n;
		for (int m = 0; m< 100&&t; m++) {
			while (a[m]--) {
				cout << m;
				t--;
				if (t) {
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}

