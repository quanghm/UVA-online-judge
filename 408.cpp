/*
 * 408.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quang
 */
#include<stdio.h>
#include <iostream>
using namespace std;
int gcd(int a,int b){
	int d=a%b;
	if (!d){
		return b;
	}
	return gcd(b,d);
}
int main(){
	int s,m;
//	bool first=true;
	while (cin>>s>>m){
//		if (first){
//			first=false;
//		}
//		else{
//			printf("\n");
//		}
		if (gcd(s,m)>1){
			printf("%10d%10d    Bad Choice\n\n",s,m);
		}else{
			printf("%10d%10d    Good Choice\n\n",s,m);
		}
	}
}
