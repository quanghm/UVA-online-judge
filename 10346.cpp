/*
 * uva10346.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quanghoang
 */
#include <iostream>
using namespace std;
int main(){
	int n,k;

	while (cin>>n>>k){
		if (k==1){cout<< n<<endl;}else
		{
			cout<< n+(n-1)/(k-1)<<endl;
		}

	}
}
