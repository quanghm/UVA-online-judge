/*
 * 11780.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main() {
	int n;
	float best[1001];
	for (int i = 1; i < 1001; i++) {
		n = i%5;
		switch (n) {
		case 1:
		case 4:
			best[i]=0.40;
			break;
		case 2:
		case 3:
			best[i]=0.20;
			break;
		case 0:
			best[i]=0;
			break;
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n==0){break;}
		printf("%.2f\n",best[n]);
	}
}
