/*
 * 10013.cpp
 *
 *  Created on: May 21, 2015
 *      Author: quanghoang
 */
#include<iostream>
using namespace std;

const int M=1000000;

int main(){
	int c,m,carry;
	int a[M]={},b[M]={};
	cin>> c;

	while (1){
		cin>>m;
		for (int i=0;i<m;i++){
			cin>>a[i]>>b[i];
		}
		carry=0;
		for (int i=m-1;i>=0;i--){
			carry+=a[i]+b[i];
			a[i]=carry%10;
			carry/=10;
		}
		for (int i=0;i<m;i++){
			cout<<a[i];
		}
		cout<<"\n";
		c--;
		if (c){
			cout<<"\n";
		}else{
			break;
		}
	}
}
