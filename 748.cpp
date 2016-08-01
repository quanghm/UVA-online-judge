/*
 * 748.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quanghoang
 */

#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;
const int N=150;
int main() {
	int n;
	string s;
	while (cin >> s >> n) {
		if (n) {
			int v[N] = { };
			v[0] = 1;

			// get base and decimal place
			int b = 0, d=0;
			for (int i = 0; i < 6; i++) {
				if (s[i] != 46) { // if a digit
					b *= 10;
					b += (s[i] - 48);	//add to base
				} else {	// if decimal point
					d = 5-i;	//record
				}
			}
//			cout<<b<< ":"<<d<<endl;
			if (b == 0) {
				printf("0\n");
			} else {
				d*=n;	// total decimal places
				s="";
				//Let's multiply
				while (n--) {
					int c=0;
					for (int i=0;i<N;i++){
						c+=v[i]*b;
						v[i]=c%10;
						c/=10;
					}
				}
				// print time

				int l=N-1,r=0;
				while (!v[l]){l--;}
				while (!v[r]){r++;}
//				cout<< d<<":"<<l<<endl;
				if (r>=d){	// integer -- no trailing  0
					for (int i=l;i>=d;i--){
						cout<<v[i];
					}
				}else{
					for (int i=l;i>=d;i--){
						cout<<v[i];
					}
					cout<<".";
					for (int i=d-1;i>=r;i--){
						cout<<v[i];
					}
				}cout<<"\n";
			}
		} else {
			// zero power
			printf("1\n");
		}
	}
}

