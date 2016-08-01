/*
 * 10432.cpp
 *
 *  Created on: May 22, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
const double pi=3.141592653589793238462643383279502884197169399375105820974;

int main(){
	int n;
	double r,s;

	while (scanf("%lf %d",&r,&n)!=EOF){
		s=n*r*r*sin(2*pi/n)/2.0;
		printf("%.3lf\n",s);
	}
}


