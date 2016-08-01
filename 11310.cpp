/*
 * 11310.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main(){
	long long a[41];
	a[0]=1;a[1]=1;a[2]=5;
	for (int i=3;i<41;i++){
		a[i]=a[i-1]+4*a[i-2]+2*a[i-3];
	}
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		printf("%lld\n",a[n]);
	}
}
