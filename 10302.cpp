/*
 * uva10302.cpp
 *
 *  Created on: May 8, 2015
 *      Author: qhoang
 */
#include<iostream>
using namespace std;

int main(){
	long long x,n;
	while (cin>>x){
		n=x*x+x;
		n/=2;
		n*=n;
		cout<<n<<"\n";
	}
}



