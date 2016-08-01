/*
 * 793.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: quanghoang
 */

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
	int c;
	int n, p, q;
	char ch;
	string line;

	cin >> c;

	while (c--) {
		cin >> n;
		getline(cin, line);
		int s = 0, f = 0,temp;
		vector<int> v;
		for (int i = 0; i <= n; i++) {
			v.push_back(i);
		}
		while (getline(cin, line) && line != "") {
			istringstream iss(line);
			iss >> ch >> p >> q;
			if (ch == 99) { //connnect p, q
				if (v[p] != v[q]) {	// only connect when they are not connected;
					temp=v[q];
					for (int i=1;i<=n;i++) {
						if (v[i] == temp) {
							v[i]= v[p];
						}
					}
				}
			} else {
				if (v[p] == v[q]) {
					s++;
				} else {
					f++;
				}
			}
		}
		if (c) {
			cout << s << "," << f << "\n\n";
		} else {
			cout << s << "," << f << "\n";
		}
	}
}

