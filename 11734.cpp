/*
 * 11734.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main() {
	int c;
	string s1, s2;

	cin >> c;
	getline(cin,s1);
	for (int i = 1; i <= c; i++) {
		getline(cin, s1);
		getline(cin, s2);

		if (s1 == s2) {
			cout << "Case " << i << ": Yes\n";
		} else {
			if (s2 == std::regex_replace(s1, std::regex("\\s+"), "")) {
				cout << "Case " << i << ": Output Format Error\n";
			} else {
				cout << "Case " << i << ": Wrong Answer\n";
			}
		}
	}
}
