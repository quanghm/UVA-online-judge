/*
 * 465.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
using namespace std;
#define maxint 2147483647
int main() {
	string line;
	bool op;
	while (getline(cin, line)) {
		long long s1 = 0, s2 = 0;
		bool isTooBig1 = false, isTooBig2 = false;
		cout << line<<"\n";
		string::iterator it = line.begin();
		while (*it>57||*it<48){
			it++;
		}
		while (*it < 58 && *it > 47) {
			if (!isTooBig1) {
				s1 = s1 * 10 + *it - 48;
				isTooBig1 = (s1 > maxint);
			}
			it++;
		}
		if (isTooBig1) {
			cout << "first number too big\n";
		}
		while (*it != 42 && *it != 43) {
			it++;
		}
		bool op = (*it == 43);	// is plus
		it++;
		while (*it < 48 || *it > 57) {
			it++;
		}
		while (it != line.end()&&*it>47&&*it<58) {
			if (!isTooBig2) {
				s2 = s2 * 10 + *it - 48;
				isTooBig2=(s2>maxint);
			}
			it++;
		}
		if (isTooBig2){
			cout<<"second number too big\n";
		}
		if (isTooBig1){
			if (op||s2){
				cout<<"result too big\n";
			}
		}else if (isTooBig2){
			if (op||s1){
				cout<<"result too big\n";
			}
		}else if ( op){
			if (s1+s2>maxint){
				cout<<"result too big\n";
			}
		}else if (s1*s2>maxint){
			cout<<"result too big\n";
		}
	}
}

