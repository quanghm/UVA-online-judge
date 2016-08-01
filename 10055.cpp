/*
 * uva10055.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;

int main(){
	long long int m,n;
	while (cin>>m>>n){
		if(m>n){
			cout<<m-n<<endl;
		}
		else{
			cout<< n-m<<endl;
		}
	}
}
