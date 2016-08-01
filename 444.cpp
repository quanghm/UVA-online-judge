/*
 * 444.cpp
 *
 *  Created on: May 19, 2015
 *      Author: qhoang
 */
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	char c;
	int num;
	int l, i;
	while (getline(cin, s)) {
		//i = 0;
		if (s[0] > 47 && s[0] < 58) {	// encoded message -- decoding
			l = s.length() - 1;
			while (l >= 0) {
				if (s[l] == 49) {
					num = 10 * s[l - 1] + s[l - 2] + 100 - 528;
					l -= 3;
				} else {
					num = s[l] * 10 + s[l - 1] - 528;
					l -= 2;
				}
				cout << (char) num;
			}
			cout << "\n";
		} else {	//normal messages -- decoding
			l = s.length();
			while (l--){
				num=s[l];
				while (num>0){
					cout<<num%10;
					num/=10;
				}
			}
			cout << "\n";
		}
	}
}

