/*
 * 10924.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: quang
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int N = 1041;

int main() {
	vector<bool> p(N, 1);
	for (int i = 2; i < 33; i++) {
		if (p[i]) {
			for (int j = i * i; j < N; j += i) {
				p[j] = 0;
			}
		}
	}
	string line;
	int s;
	while (cin >> line) {
		s = 0;
		for (string::iterator it = line.begin(); it != line.end(); it++) {
			s += ((*it < 91) ? *it - 38 : *it - 96);
		}
		if (p[s]) {
			cout << "It is a prime word.\n";
		} else {
			cout << "It is not a prime word.\n";
		}
	}
}

