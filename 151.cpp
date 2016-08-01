/*
 * uva151.cpp
 *
 *  Created on: May 4, 2015
 *      Author: qhoang
 */

#include<iostream>
using namespace std;

int main() {
	int n, m,s;
	while (cin >> n && n) {
		if (n == 13) {
			cout<<"1\n";
		} else {
			m=2;
			while (m++){
//				int a[100] = { }; // a[i]: last person in an (i+1)-queue
//				a[0] = 0;
//				a[1] = 1;
//				for (int i = 2; i < n; i++) { //a[0]=0
//					a[i] = (a[i - 1] + m) % (i);
//					if (a[i] == 0) {
//						a[i] = i;
//					}
//				}
				s=1;	//two zones
				for (int i=2;i<n;i++){
					s=(s+m)%i;
					if (s==0){
						s=i;
					}
				}
				if (s==12){
					cout<<m<<"\n";
					break;
				}
			}
		}
	}

}
