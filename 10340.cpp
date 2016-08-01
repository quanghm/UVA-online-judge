/*
 * uva10340.cpp
 *
 *  Created on: May 4, 2015
 *      Author: qhoang
 */
#include <iostream>
#include <string>
using namespace std;

int searchChar(char c, string str, int start, int end) { //find c in s starting from start to end,
	//return first occurence or -1 if not found.
	int p = start;

	while (p <= end && str[p] != c) {
		p++;
	}
	return ((p > end) ? -1 : p);
}

int main() {
	string w, e;
	int l,m,p;
	while (cin >> w >> e) {
		l = e.length();
		m=w.length();
		p=0;
		for (int i=0;i<m;i++){
			p=searchChar(w[i],e,p,l);
			if (p==-1){
				break;
			}
			else{
				p++;
			}
		}
		if (p==-1){cout<<"No"<<endl;}else{cout<<"Yes"<<endl;}
	}
	return 0;
}

