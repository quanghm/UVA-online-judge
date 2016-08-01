/*
 * uva11547.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quang
 */
#include <iostream>

using namespace std;

int main(){
	int t,n;
	cin>>t;

	while (t--){
		cin>>n;
		n*=315;
		n+=36962;
		if (n<0){n*=-1;}
		n%=100;
		n/=10;cout<<n<<endl;
	}
}



