/*
 * uva445.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quang
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	int s = 0, l;
	char c;

	while (getline(cin, line)) {
		if (line == "") {
			cout << "\n";
		} else {
			l = line.length();
			for (int i = 0; i < l; i++) {
				s = 0;
				while (line[i] >= '0' && line[i] <= '9') {
					s += (line[i] - '0');
					i++;	// get number
				}
				switch (line[i]) {
				case 'b':
					c = 32;
					break;
				case '!':
						cout <<"\n";
					break;
				default:
					c = line[i];
					break;
				}
				while (s--) {
					cout << (char) c;
				}
			}
			cout << "\n";
		}
	}
}

