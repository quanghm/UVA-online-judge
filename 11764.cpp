/*
 * 11764.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;

int main(){
	int t;
	int n;
	int i=0;
	int u,d,c,ne;
	scanf("%d",&t);
	while (i++<t){
		scanf("%d",&n);

//		if (n==1){
//			printf("Case %d: 0 0\n",i);
//		}else{
			u=0;d=0;
			scanf("%d",&c);
			n--;
			while (n--){
				scanf("%d",&ne);
				if (c<ne){u++;}
if (c>ne){d++;}
				c=ne;
			}
//		}
			printf("Case %d: %d %d\n",i,u,d);
	}
}



