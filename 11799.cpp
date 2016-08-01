/*
 * 11799.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int c,n,v;
	scanf("%d",&c);

	int i=0;
	while (i++<c){
		scanf("%d",&n);

		vector<int> s;

		while (n--){
			scanf("%d",&v);
			s.push_back(v);
		}
		sort(s.begin(),s.end());
		printf("Case %d: %d\n",i,s.back());
	}

}
