/*
 * 11000.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<long long>f;
	vector<long long>m;
	f.push_back(1);
	m.push_back(0);

	long long F,M;
	while (1){
		F=m.back()+1;
		M=f.back()+m.back();
		if(M<4294967296){
			f.push_back(F);
			m.push_back(M);
		}else{break;}
	}
	int d;
	while (scanf("%d",&d)&&d>-1){
		printf("%lld %lld\n",m[d],f[d]+m[d]);
	}
}


