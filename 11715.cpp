/*
 * 11715.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	int c,n;
	double x,y,z,a,b;
	n=0;
	while (cin>>c&&c){
		n++;
		cin>>x>>y>>z;
		switch (c){
		case 1:
			a=(y-x)/z;
			b=(x+a/2*z)*z;
			break;
		case 2:
			a=(y-x)/z;//t
			b=(x+z/2*a)*a;
			break;
		case 3:
			a=(sqrt(x*x+2*y*z)-x)/y;
			b=x+y*a;
			break;
		case 4:
			a=(x-sqrt(x*x-2*y*z))/y;
			b=x-y*a;
		}
		printf("Case %d: %.3f %.3f\n",n,b,a);
	}
}
