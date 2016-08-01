/*
 * 990.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;
const int N = 1001;
int main() {
	int t, w, c, temp;
	bool first=true;
	while (scanf("%d %d %d", &t, &w, &c) != EOF) {
		if (first){
			first=false;
		}else{
			printf("\n");
		}
		int d[31] = { };
		int v[31] = { };
		t /= 3 * w;
//		printf("%d %d %d\n----\n",t,w,c);
		int a[31][N] = { };
		for (int i = 1; i <= c; i++) {
			scanf("%d %d", d + i, v + i);
			for (int j = 1; j <= t; j++) {
				temp=j-d[i];
				a[i][j] =
						(temp>=0&&a[i - 1][temp] + v[i] > a[i - 1][j]) ?
								a[i - 1][temp] + v[i] : a[i - 1][j];
//				printf("%d ",a[i][j]);
			}
//			printf("\n");
		}
		printf("%d\n",a[c][t]);
		stack<int> tr;	// to be recovered
		w=0;
		for (int i=c;i;i--){
			temp=(t<d[i])?0:t-d[i];
			if (a[i][t]==a[i-1][temp]+v[i]){// treasure i is recovered
				t=temp;
				tr.push(i);
				w++;
			}
		}
		printf("%d\n",w);
		while(w--){
			temp=tr.top();
			tr.pop();
			printf("%d %d\n",d[temp],v[temp]);
		}
	}
}

