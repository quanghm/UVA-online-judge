/*
 * uva11150.cpp
 *
 *  Created on: May 10, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;

int main(){
	int n;
	while ((cin>>n)&&n){
		n+=(n/2);
		cout << n<<"\n";
	}
}
