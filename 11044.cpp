/*
 * uva11044.cpp
 *
 *  Created on: May 8, 2015
 *      Author: Quang Hoang
 */
#include<iostream>
using namespace std;

int main(){
	int t;
	int m,n;
	cin >> t;

	while (t--){
		cin>>m>>n;
		if (m<3||n<3){
			cout<<"0\n";
		}else{
			m-=2;n-=2;
			m=(m%3)?(m/3+1):(m/3);
			n=(n%3)?(n/3+1):(n/3);
			cout<<m*n<<"\n";
		}
	}
}

