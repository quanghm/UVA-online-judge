/*
 * 10420.cpp
 *
 *  Created on: May 7, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<map>
using namespace std;


int main(){
	map <string,int> countries;
	string c,l;
	int n;
	cin>>n;
	while (n--){
		cin>>c;
		countries[c]++;
		getline(cin,l);
	}
	for (map<string,int>::iterator it=countries.begin();it!=countries.end();it++){
		cout<<(it->first)<<" "<<(it->second)<<"\n";
	}
}
