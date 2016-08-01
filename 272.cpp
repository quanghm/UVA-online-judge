/*
 * uva272.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: quang
 */
#include <iostream>
using namespace std;
int main(){
	bool i=false;//in quote
	char c;
	while (cin>>c){
		if (c==34){
			if (i) {cout<<"''";i=0;}
			else {cout<<"``";i=1;}
		}else{
			cout<<c;
		}
	}
}



