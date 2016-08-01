/*
 * uva10929.cpp
 *
 *  Created on: May 5, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
using namespace std;

int main() {
	int s = 0, m = 1;
	string line;

	while ((getline(cin, line)) && (line != "0")) {
		s = 0;
		m = 1;
		for (string::iterator it = line.begin(); it != line.end(); ++it) {
			s += (*it - 48) * m;
			m *= (-1);
		}
		if (s % 11) {
			cout << line << " is not a multiple of 11." << endl;
		} else {
			cout << line << " is a multiple of 11." << endl;
		}
	}
}
