/*
 * uva113.cpp
 *
 *  Created on: May 3, 2015
 *      Author: quanghoang
 */
#include <cstdio>
#include<cmath>
using namespace std;

int main(){
	int n;
	double p;
	while(scanf("%d %lf",&n,&p)!=EOF){
		printf("%.0lf\n",pow(p,1.0/n));
	}
	return 0;
}



