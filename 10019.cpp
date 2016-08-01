/*
 * uva10019.cpp
 *
 *  Created on: May 8, 2015
 *      Author: Quang Hoang
 */
#include<iostream>
using namespace std;

int main(){
	int n,m;
	int t,s;
	int a[10]={0,1,1,2,1,2,2,3,1,2};
		//0-0;1-1;2-1;3-1;4-1;5-2;6-2;7-3;8-1;9-2
	cin>>n;
	while (n--){
		cin>>m;
		t=m;s=0;
		while (t){
			s+=t%2;
			t/=2;
		}
		cout<<s;
		s=0;
		while (m){
			s+=a[m%10];
			m/=10;
		}
		cout<<" "<<s<<"\n";
	}
}



