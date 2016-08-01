/*
 * uva256.cpp
 *
 *  Created on: May 10, 2015
 *      Author: quang
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	long r;
	int n,i,t,s;
	int a[5]={9,99,999,9999,99999};
	while (cin>>n){
		printf("%0*d\n",n,0);
		n/=2;
		t=a[n-1];

		for (int i=0;i<=t;i++){
			r=4*t*i+1;
			s=floor(sqrt(r));

			if (s*s==r){
				s=(s+1)/2;
				printf("%0*d%0*d\n",n,i,n,s-i);
			}
		}
	}
}



