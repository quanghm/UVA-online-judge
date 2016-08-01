/*
 * 10789.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int main() {
	vector<bool> p(2002, 1);
	p[1]=0;
	for (int i = 2; i < 45; i++) {
		if (p[i]) {
			for (int j = i * i; j < 2002; j += i) {
				p[j] = 0;
			}
		}
	}
	int n;
	char ch;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		map<char, int> f;
		priority_queue<int,vector<char>,greater<char> >pq;
		while ((ch = getchar()) != 10) {
			f[ch]+=1;
		}
		for (map<char,int>::iterator it=f.begin();it!=f.end();it++){
			if (p[it->second]){
				pq.push(it->first);
			}
		}
		if (pq.empty()){
			printf("Case %d: empty\n",i);
		}else{
			printf("Case %d: ",i);
			while (!pq.empty()){
				printf("%c",pq.top());
				pq.pop();
			}
			printf("\n");
		}
	}
}

