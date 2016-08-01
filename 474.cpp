/*
 * 474.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: quang
 */
#include<cstdio>

using namespace std;

const int N=1000001;
const float eps=1e-10;
int main(){
	float a[N];
	int b[N];
	a[0]=1;b[0]=0;

	for (int i=1;i<N;i++){
		if (a[i-1]<2){
			a[i]=a[i-1]*5.0;
			b[i]=b[i-1]+1;
		}else{
			a[i]=a[i-1]/2.0;
			b[i]=b[i-1];
		}
	}
	int n;
	while (scanf("%d",&n)!=EOF){
		printf("2^-%d = %.3fe-%d\n",n,a[n],b[n]);
	}
}
