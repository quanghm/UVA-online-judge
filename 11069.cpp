/*
 * 11069.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main(){
	int a[77];
	a[1]=1;a[2]=2;a[3]=2;
	for (int i=4;i<77;i++){
		a[i]=a[i-2]+a[i-3];
	}

	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",a[n]);
	}
}

