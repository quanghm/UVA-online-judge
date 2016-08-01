/*
 * uva575.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include <string>
using namespace std;
int main(){
	string line;
	unsigned int n=1,s,d;

	while (getline(cin,line)&&line!="0"){
		n=0;
		s=0;
		for (string::iterator it=line.begin();it!=line.end();it++){
			d=*it-'0';
			n=2*n+d;
			s+=d;
		}
		cout<<2*n-s<<endl;
	}
}
