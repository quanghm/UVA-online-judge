/*
 * 10820.cpp
 *
 *  Created on: May 23, 2015
 *      Author: quanghoang
 */
#include<cstdio>

using namespace std;

int main(){
	int primes[]={2,3,5,7, 11, 13, 17, 19, 23, 29
		, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71
		, 73, 79, 83, 89, 97,101,103,107,109,113
		,127,131,137,139,149,151,157,163,167,173
		,179,181,191,193,197,199,211,223,227,229};
	int n,phi;
	int a[50001];
	a[1]=1;
	for (int i=2;i<50001;i++){
		n=i;
		phi=i;	//phi functions
		for (int j=0;j<50&&primes[j]<=n;j++){
			if (n%primes[j]==0){
				phi/=primes[j];
				phi*=primes[j]-1;
				while(n%primes[j]==0){
					n/=primes[j];
				}
			}
		}
		if (n>1){
			phi/=n;
			phi*=(n-1);
		}
		a[i]=2*phi+a[i-1];
	}

	while (scanf("%d",&n)!=EOF&&n){
		printf("%d\n",a[n]);
	}
}


