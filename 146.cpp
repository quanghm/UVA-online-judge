/*
 * uva146.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quang
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	string line;
	int p, q, l; //position
	char c;
	while (getline(cin, line) && (line != "#")) {
		l = line.length() - 1;
		p = l;

		while ((p) && (line[p] <= line[p - 1])) {
			p--;
		}
		if (p) {
			q = p; // start at current position
			p--;	// last character before decreasing
			c = line[p];	// and character

			while ((q <= l) && (line[q] > c)) {
				q++;	//get first position that <= c
			}
			q--;	//last character >c

			for (int i = 0; i < p; i++) {	//print the head
				cout << line[i];
			}

			if (q < line.length())// q-th char
				cout << line[q];

			// print the tail
			for (int i = l; i > q; i--) {
				cout << line[i];
			}

			cout << c;	// p-th letter
			//between q and p
			for (int i = q - 1; i > p; i--) {
				cout << line[i];
			}
			cout << endl;

		} else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}

