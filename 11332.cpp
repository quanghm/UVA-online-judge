/*
 * uva11332.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quang
 */
#include <iostream>
using namespace std;

int main(){
	unsigned int n;
	while ((cin>>n)&&(n)){
		n%=9;
		cout<<((n)?(n):9)<<endl;
	}
}
