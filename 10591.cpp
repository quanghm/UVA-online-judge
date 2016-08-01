/*
 * 10591.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>

int ss(int n) {
	int r = 0, s = 0;
	while (n) {
		r = n % 10;
		n /= 10;
		s += r * r;
	}
	return s;
}
using namespace std;
int main() {
	int h[730] = { };
	int n, t;

	h[1] = 1;
	h[2] = 2;
	h[4] = 2;
	//h[4]=2;
	for (int i=3;i<730;i++){
		t=30;n=i;
		queue<int>q;
		while (t--&&!h[n]){
			q.push(n);
			//h[n]=1;
			n=ss(n);
		}
		n=(t)?h[n]:2;
		while (!q.empty()){
			h[q.front()]=n;
			q.pop();
		}
	}
	scanf("%d",&t);
	for (int c=1;c<=t;c++){
		scanf("%d",&n);
		printf("Case #%d: %d is",c,n);
		n=(n<729)?n:ss(n);
		if (h[n]%2){
			printf(" a Happy number.\n");
		}else{
			printf(" an Unhappy number.\n");
		}
	}
}

