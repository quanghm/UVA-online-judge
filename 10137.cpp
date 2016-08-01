/*
 * 10137.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: quang
 */
#include<cstdio>
#include<cstring>
#include<string>
#define N 15000

using namespace std;

int main() {
	int n;
	int d, c, s, t;
	char ch;
	int a[N];
	while (scanf("%d", &n) != EOF && n) {
		s = 0,t=0;
		ch = getchar();
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			d = 0;
			while ((ch = getchar()) != 46) {
				d = d * 10 + ch - 48;
			}
			while ((ch = getchar()) != 10) {
				d = d * 10 + ch - 48;
			}
			a[i] = d;
			s += d;
		}
		c = s / n;
		d = s % n;
		s = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < c) {
				s += c - a[i];
			} else if (a[i]>c){
				t++;
			}
		}
		if (d>t){s+=d-t;}
		//		s = s / 2 - d;
		printf("$%d.%02d\n", s / 100, s % 100);
	}
}

