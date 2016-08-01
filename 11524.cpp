/*
 * 11524.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	int c;
	double r,m1,n1,m2,n2,m3,n3,r1,r2,r3,c1,c2,c3;

	cin>>c;
	while (c--){
		cin>>r;
		cin>>m1>>n1>>m2>>n2>>m3>>n3;
		r1=m1/n1;
		r2=n2/m2;
		r3=m3/n3;

		c3=sqrt((r1+r2+1)*r3);
		c2=c3/r2;
		c1=c3/r3;

		m1=(c1+c2+c3)*r*r;
		printf("%.4f\n",m1);
	}
}



