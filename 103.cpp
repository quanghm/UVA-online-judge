/*
 * 103.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, k;
vector<int> boxes[30];


bool compare(int i, int j) {
	for (int l = 0; l < n; l++) {
		if (boxes[i][l] >= boxes[j][l]) {
			return false;
		}
	}
	return true;
}
int main() {
	int temp;
	while (scanf("%d %d", &k, &n) != EOF) {
		//boxes.clear();
		vector<int> index;
		for (int i = 0; i < k; i++) {
			boxes[i].clear();
			index.push_back(i);
			for (int j = 0; j < n; j++) {
				scanf("%d", &temp);
				boxes[i].push_back(temp);
			}
			sort(boxes[i].begin(), boxes[i].end());
		}

		sort(index.begin(),index.end(),compare);

		bool edge[30][30]={};
		for (int i=0;i<k;i++){
			for (int j=i+1;j<k;j++){
				edge[i][j]=compare(i,j);
			}
		}
		for (int i=0;i<k;i++){
			printf("%d:",index[i]+1);
			for (int j=0;j<n;j++){
				printf("%d ",boxes[index[i]][j]);
			}
			printf("\n");
		}
		vector<int> d(k,1);
		vector<int> pre(k);
		int max=0, pos;

		for (int j=k-1;j>=0;j--){
			for (int i=j-1;i>=0;i--){
				if (edge[index[i]][index[j]]){
					if (d[index[i]]<=d[index[j]]){
						d[index[i]]=d[index[j]]+1;
						pre[i]=j;
					}

					if (d[index[i]]>max){
						max=d[index[i]],pos=i; //where it begins
					}
				}
			}
		}

		printf("%d\n",max);
		for (int i=max;i>=0;i--){
			printf("%d",index[pos]+1);
			pos=pre[pos];
			if (i){printf(" ");}else{printf("\n");}
		}
	}
}

