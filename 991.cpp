/*
 * 991.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;

int main(){
	int h[11]={};
	h[0]=1;
	h[1]=1;
	h[2]=2;
	for (int t=3;t<11;t++){
		for (int j=0;j<t;j++){
			h[t]+=h[j]*h[t-j-1];
		}
	}
	int t;
	bool first=1;
	while (cin>>t){
		if (first){
			first=false;
		}else{cout<<"\n";}
		cout<<h[t]<<"\n";
	}
}
