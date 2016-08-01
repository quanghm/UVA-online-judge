/*
 * uva579.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quang
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(){
	int h,m;
	string line;
	char c;
	float a;
	while (scanf("%d :%d",&h,&m)){
		if(!((m)||(h))) {return 0;}
		a= (30*h-5.5*m);
		if (a<0){a=-a;}
		if (a>180){a=360-a;}
		printf("%.3f\n",a);
	}
}
