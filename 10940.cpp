/*
 * 10940.cpp
 *
 *  Created on: May 24, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;
const int N=500000;
int main(){

	int a[N];

	a[0]=0;

	for (int i=1;i<N;i++){
		a[i]=(a[i-1]+2)%(i+1);
	}

	int n;

	while (scanf("%d",&n)!=EOF&&n){
		if (n&(n-1)){// n is a power of 2
			printf("%d\n",a[n-1]);
		}else{
			printf("%d\n",n);
		}
	}
}


