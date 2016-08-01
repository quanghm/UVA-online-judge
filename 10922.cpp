/*
 * 10922.cpp
 *
 *  Created on: May 22, 2015
 *      Author: qhoang
 */
#include<iostream>
#include <string>
using namespace std;
int degree(int n) {
	if (n == 9)
		return 1;
	if (n < 9)
		return 0;
	int s = 0;
	while (n) {
		s += n % 10;
		n /= 10;
	}
	return degree(s) + 1;
}
int main() {
	string line;
	int s;
	while (getline(cin,line)&&line!="0"){
		s=0;
		for (string::iterator it=line.begin();it!=line.end();it++){
			s+=(*it-48);
		}
		if (s%9){
			cout<<line<<" is not a multiple of 9.\n";
		}else{
			cout<<line<<" is a multiple of 9 and has 9-degree "<<degree(s)<<".\n";
		}
	}
}

