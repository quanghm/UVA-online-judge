/*
 * 10790.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main(){
	long long a,b;
	long long s;
	int c=0;
	while (scanf("%lld%lld",&a,&b)&&a){
		s=a*(a-1)*b*(b-1)/4;
		printf("Case %d: %lld\n",++c,s);
	}
}
