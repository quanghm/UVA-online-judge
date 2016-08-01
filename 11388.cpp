/*
 * 11388.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;

int main(){
	int c,g,l;

	scanf("%d",&c);
	while (c--){
		scanf("%d%d",&g,&l);
		if (l%g){
			printf("-1\n");
		}else{
			printf("%d %d\n",g,l);
		}
	}
}



