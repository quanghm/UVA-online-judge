/*
 * 11530.cpp
 *
 *  Created on: May 28, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	string line;
	cin>>t;
	getline(cin,line);
	for (int c=1;c<=t;c++){
		getline(cin,line);
		int s=0;
		for (string::iterator it=line.begin();it!=line.end();it++){
			switch (*it){
			case 'a':
			case 'd':
			case 'g':
			case 'j':
			case 'm':
			case 'p':
			case 't':
			case 'w':
			case 32:
				s+=1;
				break;
			case 'b':
			case 'e':
			case 'h':
			case 'k':
			case 'n':
			case 'q':
			case 'u':
			case 'x':
				s+=2;
				break;
			case 'c':
			case 'f':
			case 'i':
			case 'l':
			case 'o':
			case 'r':
			case 'v':
			case 'y':
				s+=3;
				break;
			case 's':
			case 'z':
				s+=4;
				break;
			}
		}
		cout<<"Case #"<<c<<": "<<s<<"\n";
	}
}

