/*
 * 10921.cpp
 *
 *  Created on: May 22, 2015
 *      Author: qhoang
 */
#include<iostream>
#include<string>

using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		for (string::iterator it = line.begin(); it != line.end(); it++) {
			switch (*it) {
			case 'A':
			case 'B':
			case 'C':
				cout << "2";
				break;
			case 'D':
			case 'E':
			case 'F':
				cout << '3';
				break;
			case 'G':
			case 'H':
			case 'I':
				cout << '4';
				break;
			case 'J':
			case 'K':
			case 'L':
				cout << '5';
				break;
			case 'M':
			case 'N':
			case 'O':
				cout << '6';
				break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				cout << '7';
				break;
			case 'T':
			case 'U':
			case 'V':
				cout<< '8';
				break;
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				cout<<'9';
				break;
			default:
				cout<<(char)(*it);
				break;
			}
		}
		cout<<"\n";
	}
}

