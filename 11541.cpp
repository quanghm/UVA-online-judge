/*
 * 11541.cpp
 *
 *  Created on: May 28, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
using namespace std;

int main() {
	int t, s;
	cin >> t;
	char c;

	string line;
	getline(cin, line);

	for (int d = 1; d <= t; d++) {
		getline(cin, line);
		cout << "Case " << d << ": ";

//		if (line==""){
//			cout<<"\n";
//		}else{
		string::iterator it = line.begin();
		while (1) {
			c = *it;
			s = 0;
			it++;
			while (it != line.end() && 47 < *it && *it < 58) {
				s *= 10;
				s += (*it - '0');
				it++;
			}
			while (s--) {
				cout << (char) c;
			}
			if (it == line.end()) {
				break;
			}
		}
		cout << "\n";
	}
//	}
}

