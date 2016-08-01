/*
 * 195.cpp
 *
 *  Created on: May 20, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(char i, char j) {
	char u=tolower(i);
	char v=tolower(j);
	if (u==v) {
		return i<j;
	} else {
		return u<v;
	}
}
int main() {
	int n;
	string line;
	cin>>n;
	getline(cin,line);
	while (n--){
		getline(cin,line);
		sort(line.begin(),line.end(),compare);
		do {
			cout<<line<<"\n";
		}while (next_permutation(line.begin(),line.end(),compare));
	}
}

