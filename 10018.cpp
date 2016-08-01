/*
 * 10018.cpp
 *
 *  Created on: May 21, 2015
 *      Author: quanghoang
 */
#include<iostream>
using namespace std;

int main(){
	int c;
	unsigned long n,reverse,temp,count=0;
	cin>>c;
	while (c--){
		cin>>n;
		count=0;
		while (1){
			temp=n;
			reverse=0;
			while (temp){
				reverse*=10;
				reverse+=temp%10;
				temp/=10;
			}
			if (reverse==n){
				cout<<count<<" "<<n<<"\n";
				break;
			}else{
				n+=reverse;
				count++;
			}
		}
	}
}



