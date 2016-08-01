/*
 * 729.cpp
 *
 *  Created on: May 23, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int c;

	int n, h;
	string line;

	cin >> c;
	while (c--) {
		line = "";
		cin >> n >> h;

		for (int i = 0; i < h; i++) {
			line = '1'+line;
		}
		for (int i = h; i < n; i++) {
			line = '0'+line;
		}
		do {
			cout << line << "\n";
		} while (next_permutation(line.begin(), line.end()));
		if (c){
			cout<<"\n";
		}
	}
}

