/*
 * uva11854.cpp
 *
 *  Created on: May 9, 2015
 *      Author: quang
 */
#include <iostream>
using namespace std;

int main(){
	long a,b,c,d;

	while ((cin>>a>>b>>c)&&a){
		if (a>b){d=a;a=b;b=d;}
		if (b>c){d=b;b=c;c=d;}

		a=a*a;b=b*b;c=c*c;
		if (a+b==c){
			cout<< "right\n";
		}else{
			cout<<"wrong\n";
		}
	}
}


