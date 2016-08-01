/*
 * uva10260.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>
using namespace std;

int main(){
	int a[91]={};
	int l,c;
	string line;
	//a['A']=a['E']=a['I']=a['O']=a['U']=a['H']=a['W']=a['Y']=0;
	a['B']=a['F']=a['P']=a['V']=1;
	a['C']=a['G']=a['J']=a['K']=a['Q']=a['S']=a['X']=a['Z']=2;
	a['D']=a['T']=3;
	a['L']=4;
	a['M']=a['N']=5;
	a['R']=6;

	while (getline(cin,line)){
		l=line.length();
		for (int i=0;i<l;i++){
			c=a[line[i]];
			if (c){
				cout<<c;
			}
			while (i<l&& a[line[i+1]]==c){
				i++;
			}
		}
		cout<<"\n";
	}
}



