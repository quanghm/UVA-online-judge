/*
 * uva11875.cpp
 *
 *  Created on: May 3, 2015
 *      Author: quanghoang
 */
#include <iostream>

using namespace std;

int main(){
	int n, m, //member
	i,//index
	a,//age
	o
	;
	cin>> n;
	string line;
	for(int c=1;c<=n;c++){
		cin>>m;
		o=m/2+1;
		for (int j=0;j<o;j++){
			cin>>a;
		}
		cout<< "Case "<< c<< ": "<<a<<endl;
		getline(cin,line);
	}
}
