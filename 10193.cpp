/*
 * 10193.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quang
 */
#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	int t, s1, s2, temp;
	cin >> t;
	getline(cin, s);

	for (int c = 1; c <= t; c++) {
		//get binary and convert s1
		getline(cin, s);
		s1 = 0;
		for (string::iterator it = s.begin(); it != s.end(); it++) {
			s1 *= 2;
			s1 += (*it == 49);
		}

		//get binary and convert s1
		getline(cin, s);
		s2 = 0;
		for (string::iterator it = s.begin(); it != s.end(); it++) {
			s2 *= 2;
			s2 += (*it == 49);
		}

		//compute gcd
		while (s1) {
			temp = s1;
			s1 = s2 % s1;
			s2 = temp;
		}
		if (s2 == 1) {
			cout << "Pair #" << c << ": Love is not all you need!\n";
		} else {
			cout << "Pair #" << c << ": All you need is love!\n";
		}
	}
}

