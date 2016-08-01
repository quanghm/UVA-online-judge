/*
 * uva483.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quang
 */
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

int main() {
	string line;
	stack<char> word;

	while (getline(cin, line)) {
		for (string::iterator it = line.begin(); it != line.end(); ++it) {
			if (*it != 32) {
				word.push(*it);
			} else {
				while (!word.empty()) {
					cout << word.top();
					word.pop();
				}
				cout << " ";
			}
		}
		while (!word.empty()) {
			cout << word.top();
			word.pop();
		}
		cout << endl;
	}
}

