/*
 * 10026.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

float r[1001];
bool compare(int i, int j) {
	return ((r[i] < r[j]) || (r[i] == r[j] && i < j));
}
int main() {
	int n, c, i;
	float s, t;
	vector<int> index(1001);
	scanf("%d", &c);

	while (c--) {
		scanf("%d", &n);
		i = 0;
		while (i < n) {
			index[i] = ++i;
			scanf("%f %f", &s, &t);
			r[i] = s / t;
//			printf("%d %.5f--\n",i,r[i]);
		}
		sort(index.begin(), index.begin() + n, compare);

		printf("%d",index[0]);
		for (int i=1;i<n;i++){
			printf(" %d",index[i]);
		}
		if(c){
			printf("\n\n");
		}else{
			printf("\n");
		}
	}
}

