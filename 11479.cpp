/*
 * 11479.cpp
 *
 *  Created on: May 28, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
using namespace std;

int main(){
	int t,a;
	long long b[3];

	scanf("%d",&t);
	for (int c=1;c<=t;c++){
		priority_queue<long long>s;
		for (int i=0;i<3;i++){
			scanf("%d",&a);
			s.push(a);
		}
		printf("Case %d: ",c);
		for (int i=0;i<3;i++){
			b[i]=s.top();
			s.pop();
		}
		if (b[0]>=b[1]+b[2]){
			printf("Invalid\n");
		}else if (b[0]==b[2]){
			printf("Equilateral\n");
		}else if (b[0]==b[1]||b[1]==b[2]){
			printf("Isosceles\n");
		}else {
			printf("Scalene\n");
		}
	}
}


