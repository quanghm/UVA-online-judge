/*
 * 10784.cpp
 *
 *  Created on: May 30, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<math.h>
using namespace std;

int main(){
	long long n,m;

	int c=1;
	while (scanf("%lld",&n)&&n){
		m=int((sqrt(8*n+1)-1)/2.0)+3;
		printf("Case %d: %lld\n",c++,m);
	}
}


