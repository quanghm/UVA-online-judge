/*
 * =====================================================================================
 *
 *       Filename:  10783.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/09/2016 22:22:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cstdio>
using namespace std;

int main(){
	int t, a,b;

	scanf("%d",&t);

	for (int i = 0; i<t; ){
		scanf("%d%d",&a,&b);
//		a = a|1;
//		int sum =0;
//		for (;a<=b;a+=2){
//			sum+=a;
//		}
		a /=2;
		b = (b+1)/2;
		int sum = b*b - a*a;
		printf("Case %d: %d\n",++i,sum);
	}
}
