/*
 * uva424.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include <string>

using namespace std;
int toNum(char c) {
	return c-48;
}
int main() {
	string line;
	int s[102] = { };	//sum here
	int u = 0;
	//read line

	while (getline(cin, line) && line != "0") {
		// reset tracker
		u = 0;
		// add to sum
		for (int i=line.length()-1;i>=0;i--) {
			s[u] += (line[i]-48);
			u++;
		}
	}
	// decode sum
	for (int i = 0; i < 100; i++) {
		u=s[i];
		//get hundreds
		s[i+2]+=( u / 100);
		u%=100;
		//get tens
		s[i+1]+=(u/10);
		u%=10;
		//get unit
		s[i]=u;
	}

	//printing
	u=101;
	while ((u)&&!(s[u])){
		u--;
	}
	if (u){	//some non-zero digits starting at u
		while(u){
			cout<< s[u--];
		}
	//}else{// no non-zero digits, sum is 0;
		cout << (s[0])<<endl;
	}
}

