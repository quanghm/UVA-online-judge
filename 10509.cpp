/*
 * 10509.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;
int main() {
	int cube[101];
	int sq[101];
	for (int i = 0; i < 101; i++) {
		sq[i]=i*i;
		cube[i] = sq[i] * i;
	}
	double f;
	int n;
	while (scanf("%lf",&f)&&f){
		n=100;
		while (cube[n]>f){
			n--;
		}
		f-=cube[n];
		f/=3.0*sq[n];
		f+=n;
		printf("%.4lf\n",f);
	}
}
