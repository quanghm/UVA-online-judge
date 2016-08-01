/*
 * 10918.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;

int main(){
	int a[31]={};
	int s=0;
	a[0]=1;
	for (int i=2;i<31;i+=2){
		s+=a[i-2];
		a[i]=2*s+a[i-2];
	}

	while (scanf("%d",&s)!=EOF&&(s!=-1)){
		printf("%d\n",a[s]);
	}
}


