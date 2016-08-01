/*
 * uva900.cpp
 *
 *  Created on: May 8, 2015
 *      Author: qhoang
 */
#include<iostream>
using namespace std;

int main(){
	unsigned long fib[51]={};
	fib[1]=1;
	fib[2]=2;
	int n=2;
	while (n++<52){
		fib[n]=fib[n-1]+fib[n-2];
	}
	while((cin>>n)&&n){
		cout<<fib[n]<<"\n";
	}
}
