/*
 * uva11192.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	int n,c,i=0,l;
	char ch;
	string line;
	stack<char>s;

	while((cin>>n)&&(n)){
		cin>>line;
		l=line.length();
		c=l/n;
		for (int j=0;j<l;j++){
			s.push(line[j]); // add char to stack
			i++;
			if (i==c){	// has c characters in stack, printing
				while (!s.empty()){
					cout<<s.top();
					s.pop();
					i--;
				}
			}
		}
		cout<<endl;
	}
}
