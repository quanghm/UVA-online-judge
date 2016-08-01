/*
 * 147.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: qhoang
 */
#include<cstdio>
using namespace std;

#define N 6001
int main(){
	int c[]={1,2,4,10,20,40,100,200,400,1000,2000};

	long long a[11][N]={};
	for (int j=0;j<N;j++){
		a[0][j]=1;
	}

	for (int i=1;i<11;i++){
		for (int j=0;j<N;j++){
			if (j<c[i]){
				a[i][j]=a[i-1][j];
			}else{
				a[i][j]=a[i-1][j]+a[i][j-c[i]];
			}
		}
	}
//	for (int j=1;i<12;i++)

	float n;
	int u;
	while (scanf("%f",&n)!=EOF&&(n>0)){
		u=(int)(n*20);
		printf("%6.2f%17lld\n",n,a[10][u]);
	}
}



