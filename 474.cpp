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
double a[N];
int b[N];
int main(){
	a[0]=1;b[0]=0;

	for (int i=1;i<N;i++){
		if (a[i-1]<2){	// integer part is odd
			a[i]=a[i-1]/2;
			b[i]=b[i-1]+1;
			a[i]*=10;
		}else{	// integer part is even
			a[i]=a[i-1]/2;
			b[i]=b[i-1];
		}
	}
	int n,i,f;	// i is integer part, f is float part
	while (scanf("%d",&n)!=EOF){
		printf("2^-%d = %.3fe-%d\n",n,a[n],b[n]);
	}
}
