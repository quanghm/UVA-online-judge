/*
 * 11223.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string line;
	string word;
	map<string, char> d;
	d[".-"] = 65;
	d["-..."] = 66;
	d["-.-."] = 67;
	d["-.."] = 68;
	d["."] = 69;	//E
	d["..-."] = 70;
	d["--."] = 71;
	d["...."] = 72;
	d[".."] = 73;
	d[".---"] = 74;	//J
	d["-.-"] = 75;
	d[".-.."] = 76;
	d["--"] = 77;
	d["-."] = 78;
	d["---"] = 79;	//O
	d[".--."] = 80;
	d["--.-"] = 81;
	d[".-."] = 82;
	d["..."] = 83;
	d["-"] = 84;	//T
	d["..-"] = 85;
	d["...-"] = 86;
	d[".--"] = 87;
	d["-..-"] = 88;
	d["-.--"] = 89;
	d["--.."] = 90;

	d["-----"] = 48;
	d[".----"] = 49;
	d["..---"] = 50;
	d["...--"] = 51;
	d["....-"] = 52;
	d["....."] = 53;
	d["-...."] = 54;
	d["--..."] = 55;
	d["---.."] = 56;
	d["----."] = 57;

	d[".-.-.-"] = 46;
	d["--..--"] = 44;
	d["..--.."] = 63;
	d[".----."] = 39;
	d["-.-.--"] = 33;
	d["-..-."] = 47;
	d["-.--."] = 40;
	d["-.--.-"] = 41;
	d[".-..."] = 38;

	d["---..."] = 58;
	d["-.-.-."] = 59;
	d["-...-"] = 61;
	d[".-.-."] = 43;
	d["-....-"] = 45;
	d["..--.-"] = 95;
	d[".-..-."] = 34;
	d[".--.-."] = 64;

	//d[""]=32;

	int n, sp;
	cin >> n;
	getline(cin, line);
	for (int i = 1; i <= n; i++) {
		getline(cin, line);
		if (i > 1) {
			cout << "\n";
		}
		cout << "Message #" << i << "\n";

		string::iterator it = line.begin();
		while (*it == 32) {
			it++;
		}

		while (1) {
			word = "";
			while (it != line.end() && *it != 32) {
				word += *it;
				it++;
			}

			cout << d[word];
			sp = 0;
			while (it != line.end() && *it == 32) {	// get spaces
				sp++;
				it++;
			}

			if (it == line.end()) {
				cout << "\n";
				break;
			} else {
				if (sp > 1) {
					cout << " ";
				}
			}
		}
	}
}

