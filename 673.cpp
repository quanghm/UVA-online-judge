/*
 * uva673.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quang
 */
#include <iostream>
#include <string>
#include<stack>
using namespace std;
int main() {
	string line;
	int n;

	cin >> n;
	getline(cin, line);
	while (n--) {
		getline(cin, line);
		stack<char> c;
		bool correct = 1;
		for (string::iterator it = line.begin(); it != line.end(); ++it) {
			if (*it == 40 || *it == 91) { //opening a new pair
				c.push(*it);
			} else { // closing
				if (c.empty()) {
					correct = 0;
					break;
				} else if ((*it == 41 && c.top() == 91)
						|| (*it == 93 && c.top() == 40)) { // mismatch
					correct = 0;
					break;
				} else
					c.pop();
			}
		}
		if ((correct) && c.empty()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}

