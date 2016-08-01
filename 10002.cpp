/*
 * uva10002.cpp
 *
 *  Created on: May 4, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	int x,y;
	float sx,sy;

	while ((cin>>n)&&(n>2)&&(n<101)){
		sx=0;sy=0;
		for (int i=0;i<n;i++){
			cin>>x>>y;
			sx+=x;sy+=y;
		}
		sx/=n;sy/=n;
		printf("%.3f %.3f\n",sx,sy);
	}
	return 0;
}

