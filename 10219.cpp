/*
 * 10219.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: quang
 */
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n,k;

	double s;
	while (scanf("%d%d",&n,&k)!=EOF){
		k=(n>2*k)?k:n-k;
		s=0;
		for (int i=1;i<=k;i++){
			s+=log10(n+1-i)-log10(i);
		}
		printf("%d\n",(int)(s)+1);
	}
}

