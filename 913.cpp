/*
 * 913.cpp
 *
 *  Created on: May 15, 2015
 *      Author: qhoang
 */
#include<iostream>
using namespace std;

int main(){
	long long n;
	while (cin>>n){
		n=n/2+1;
		n=6*n*n-9;
		cout<<n<<'\n';
	}
}
