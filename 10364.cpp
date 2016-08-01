/*
 * 10364.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int n,m,s;

	scanf("%d",&n);

	while (n--){
		scanf("%d",&m);
		vector<int>a(m);
		s=0;
		for (vector<int>::iterator it=a.begin();it!=a.end;it++){
			scanf("%d",it);
			s+=*it;
		}
		if (s%4){
			printf("No\n");
		}else{
			s/=4;	// length;

		}
	}
}



