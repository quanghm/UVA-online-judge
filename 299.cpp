/*
 * uva299.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: Quang Hoang
 */
#include <iostream>
using namespace std;
int main(){
	int n=0;
	int m=0;
	int s=0;
	cin>> n;
	while (n--){
		cin>>m;
		s=0;
		int a[m]={};
		for (int i=0;i<m;i++){
			cin>>a[i];
		}
		for (int i=0;i<m;i++){
			for (int j=i+1;j<m;j++){
				if (a[i]>a[j]){s++;}
			}
		}
		cout<< "Optimal train swapping takes "<< s<< " swaps."<<endl;
	}
}


