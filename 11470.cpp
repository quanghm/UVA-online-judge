/*
 * 11470.cpp
 *
 *  Created on: May 24, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;

int main(){
	int c=0,n,s,m;

	int a[10][10];
	while (scanf("%d",&n)!=EOF&&n){
		printf("Case %d:",++c);

		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				scanf("%d ",&(a[i][j]));
			}
		}
		m=n/2;
		for (int i=0;i<m;i++){
			s=0;
			for (int j=i;j<n-i-1;j++){
				s+=(a[i][j]+a[j][n-1-i]+a[n-1-i][n-1-j]+a[n-1-j][i]);
//				printf("%d+%d+%d+%d\n",a[i][j],a[j][n-1-i],a[n-1-i][n-1-j],a[n-1-j][i]);
			}
			printf(" %d",s);
			//s+=(a[])
		}
		if (n%2){
			printf(" %d",a[m][m]);
		}
		printf("\n");

	}
}



