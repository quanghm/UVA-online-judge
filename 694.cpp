/*
 * uva694.cpp
 *
 *  Created on: May 4, 2015
 *      Author: qhoang
 */
#include <iostream>
using namespace std;

int main(){
	long a,l,c=0,t=0;

	while ((cin>>a>>l)&&(a>0)&&(l>0)){
		t=1;c++;
		cout<<"Case "<<c<<": A = "<<a<<", limit = "<<l<<", number of terms = ";
		while (a!=1){
			a=(a%2)?(3*a+1):(a/2);
			if (a>l)break;
			t++;
		}
		cout<< t<<endl;
	}
}



