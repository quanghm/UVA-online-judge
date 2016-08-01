/*
 * uva476.cpp
 *
 *  Created on: May 8, 2015
 *      Author: qhoang
 */
#include <iostream>
using namespace std;

int main() {
	char c;
	int n = 1;
	double rec[11][4];
	double x, y;
	while ((cin >> c) && c == 'r') {
		cin >> rec[n][0]>>rec[n][1]>>rec[n][2]>>rec[n][3];
		n++;
	}
	// c= *; reading points;
	int p = 0;
	// reading points;
	bool flag = 0;
	while ((cin >> x >> y) && (!(x == 9999.9 && y == 9999.9))) {
		p++;	// increase point number
		flag = 0;	//each point
		for (int i = 1; i < n; i++) {
			if (x > rec[i][0] && x < rec[i][2] && y < rec[i][1]
					&& y > rec[i][3]) {
				cout << "Point " << p << " is contained in figure " << i
						<< "\n";
				flag = 1;
			}
		}
		if (!flag) {
			cout << "Point " << p << " is not contained in any figure\n";
		}
	}
}

