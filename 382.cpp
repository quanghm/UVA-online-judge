/*
 * uva382.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include <stdio.h>

using namespace std;
int main() {
	int n = 60000;
	int i = 1, s;
	int phi = 0;
	bool a[60000] = { };

	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		for (int j = 2 * i; j < n; j += i) { // kill multiple of i
			a[j] = true;
		}
	}
	cout<<"PERFECTION OUTPUT"<<endl;
	while ((cin >> n) && (n)) {	//read input
		phi = 1;	// sum is 1
		i=n;
		for (int j=2;j<=n;j++){
			while (a[j]){j++;}
			if (n%j==0){
				s=j;
				while(n%j==0){
					s*=j;
					n/=j;
				}
				phi*=(s-1);phi/=j-1;
			}
		}
		phi-=i;
		if (phi<i) {printf("%5d  DEFICIENT\n",i);}
		if (phi==i){printf("%5d  PERFECT\n",i);}
		if (phi>i){printf("%5d  ABUNDANT\n",i);}
		}
	cout<<"END OF OUTPUT"<<endl;
}

