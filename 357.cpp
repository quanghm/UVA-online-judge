/*
 * uva357.cpp
 *
 *  Created on: May 8, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;
const int n=30001;
int main(){
	long long a[n]={};//1 and 5
	long long b[n]={};//1 and 5 and 10;
	long long c[n]={};//1 and 5 and 10 and 25;
	long long d[n]={};//1 and 5 and 10 and 25 and 50;

	a[0]=a[1]=a[2]=a[3]=a[4]=1;
	for (int i=5;i<n;i++){
		a[i]=a[i-5]+1;
	}
	for (int i=0;i<10;i++){
		b[i]=a[i];
	}
	for (int i=10;i<n;i++){
		b[i]=b[i-10]+a[i];
	}
	for (int i=0;i<25;i++){
		c[i]=b[i];
	}
	for (int i=25;i<n;i++){
		c[i]=c[i-25]+b[i];
	}
	for (int i=0;i<50;i++){
		d[i]=c[i];
	}
	for (int i=50;i<n;i++){
		d[i]=d[i-50]+c[i];
	}
	int m;
	while (cin>>m){
		if (m<5){
			cout<< "There is only 1 way to produce "<<m<<" cents change.\n";
		}
		else {
			cout<< "There are "<<d[m]<<" ways to produce "<<m<<" cents change.\n";
		}
	}
}
