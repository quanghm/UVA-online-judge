/*
 * 477.cpp
 *
 *  Created on: May 21, 2015
 *      Author: qhoang
 */
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
	int m = 0, n = 0;
	char type[10];
	double co[10][4];
	char c;

	while (cin >> c && c != 42) {

		if (c == 99) {
			cin >> co[n][0] >> co[n][1] >> co[n][2];
		} else if (c == 114) {
			cin >> co[n][0] >> co[n][1] >> co[n][2] >> co[n][3];
		} else {
			cout << "invalid entry\n";
			return 0;
		}
		type[n] = c;
		n++;
	}
	double x, y, dx, dy;
	bool flag;
	while ((cin >> x >> y) && (x != 9999.9 || y != 9999.9)) {
		flag = true;
		m++;
		for (int i = 0; i < n; i++) {
			if (type[i] == 99) {
				dx = co[i][0] - x;
				dy = co[i][1] - y;
				if (sqrt(dx * dx + dy * dy) < co[i][2]) {
					cout << "Point " << m << " is contained in figure " << i + 1
							<< "\n";
					flag = false;
				}
			} else if (type[i] == 114) {
				if (co[i][0] < x && x < co[i][2] && co[i][1] > y
						&& co[i][3] < y) {
					cout << "Point " << m << " is contained in figure " << i + 1
							<< "\n";
					flag = false;
				}
			}
		}
		if (flag) {
			cout << "Point " << m << " is not contained in any figure\n";
		}
	}
}

