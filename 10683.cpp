/*
 * 10683.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<string>
using namespace std;

int main() {
	int time,h,m,s;
	long long t;
	while (scanf("%d", &time) != EOF) {
		s=time%10000;
		time/=10000;
		m=time%100;
		h=time/100;
//		printf("%02d:%02d:%04d\n",h,m,s);

		t=(h*60+m)*6000+s;
		// t is total time since 00:00:00.00
		t*=1000;
		t/=864;
		printf("%07lld\n",t);
	}
}

