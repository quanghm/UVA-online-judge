/*
 * 11743.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<string>
using namespace std;

int main(){
	char c[19];
	int d,s;
	int D[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	int n;
	bool m;
	scanf("%d",&n);
	fgets(c,19,stdin);
	while (n--){
		fgets(c,100,stdin);
		s=0;m=true;
		for (int i=0;i<18;i++){
			d=c[i]-48;
			if (d!=-16){
				if(m){s+=D[d];m=false;}else{s+=d;m=true;}
			}
		}

		s+=(int)c[18]-48;

		if (s%10){
			puts("Invalid");
		}else{
			puts("Valid");
		}
	}
}
