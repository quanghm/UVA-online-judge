/*
 * uva10215.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quang
 */
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int main(){
	double w,l;
	double a,b,c;

	while (scanf("%lf %lf",&l,&w)!=EOF){
		if (w>l){a=w;w=l;l=a;}
		a=w+l;b=w*l;
		c=w*w+l*l-b;

		printf("%.3lf %.3lf %.3lf\n", (a-sqrt(c))/6.0+1e-10,0.0,w/2.00+1e-10);
	}
}



