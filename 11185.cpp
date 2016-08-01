/*
 * 11185.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<stack>
using namespace std;

int main(){
	int n;
	while (scanf("%d",&n)&&n>=0){
		if (n){
			stack<int> t;
			while(n){
				t.push(n%3);
				n/=3;
			}
			while (!t.empty()){
				printf("%d",t.top());
				t.pop();
			}
			printf("\n");
		}else{
			printf("0\n");
		}
	}
}


