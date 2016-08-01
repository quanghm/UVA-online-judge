/*
 * 11359.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t,n,s;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		{
			if (n<3){
				while (n--){
					scanf("%d",&s);
				}
				printf("0\n");
			}else{
				vector<int>val;
				for (int i=0;i<n;i++){
					scanf("%d",&s);
					val.push_back(s);
				}
				s=0;
				sort(val.begin(),val.end());
				for (int i=n-3;i>=0;i-=3){
					s+=val[i];
				}
				printf("%d\n",s);
			}
		}
	}
}


