/*
 * uva11461.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a,b;

	while ((cin>>a>>b)&&a){
		a=floor(sqrt(b))-floor(sqrt(a-1));
		cout<<a<<"\n";
	}
}
