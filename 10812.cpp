/*
 * uva10812.cpp
 *
 *  Created on: May 4, 2015
 *      Author: qhoang
 */
#include <iostream>
using namespace std;

int main() {
	int c, s, d;
	cin >> c;

	while (c--) {
		cin >> s >> d;
		if ((s < d) || ((s & 1) ^ (d & 1))) {
			cout << "impossible" << endl;
		} else {
			d = (s - d) / 2;
			s = s - d;
			cout << s << " " << d << endl;
		}
	}
}

