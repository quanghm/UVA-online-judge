/*
 * 10931.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<stack>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		int s = 0;
		stack<bool> bi;
		bool t;

		while (n){
			t=n%2;
			n/=2;
			s+=t;
			bi.push(t);
		}
		printf("The parity of ");
		while (!bi.empty()){
			printf("%d",bi.top());
			bi.pop();
		}
		printf(" is %d (mod 2).\n",s);
	}
}

