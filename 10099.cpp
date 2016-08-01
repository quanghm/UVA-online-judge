/*
 * 10099.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#define N 101
#define INF 2147483647

using namespace std;
vector<int> d;

class compare {
public:
	bool operator()(int i, int j) {
		return d[i] < d[j];
	}
};

// // naive approach
int main() {
	int n, r;
	int c = 0, c1, c2, p, S, D, T, temp;
	while (scanf("%d %d", &n, &r) != EOF && n) {
		vector<int> edges[N];
		bool checked[N] = { };
		int e[N][N] = { };
		d.resize(n + 1, INF);

		for (int i = 0; i < r; i++) {
			scanf("%d %d %d", &c1, &c2, &p);
			edges[c1].push_back(c2);
			edges[c2].push_back(c1);

			e[c1][c2] = p;
			e[c2][c1] = p;
		}
		scanf("%d %d %d", &S, &D, &T);
		queue<int> v;
		priority_queue<int> dist;
		v.push(S);
		while (!v.empty()) {
			c1 = v.front();
			v.pop();
			checked[c1] = 1;
			for (vector<int>::iterator it = edges[c1].begin();
					it != edges[c1].end(); it++) {
				if (!checked[*it] && *it != D) {
					v.push(*it);
				}

				if (d[c1] > e[c1][*it]) {
					temp = e[c1][*it];
				} else {
					temp = d[c1];
				}
				if (d[*it] < temp || d[*it] == INF) {
					d[*it] = temp;
				}

				if (*it == D) {
					dist.push(d[*it]);
				}
			}
		}
		d[D]--;
		if (T % d[D]) {
			T = T / d[D] + 1;
		} else {
			T = T / d[D];
		}
		printf("Scenario #%d\nMinimun Number of Trips = %d\n\n", ++c, T);
	}
}

// dijistra
//int main() {
//	int n, r, c1, c2, p,S,D,T,temp;
//
//	while (scanf("%d %d", &n, &r) && n) {
//		d.resize(N, 0);
//		int e[N][N] = { };
//		bool checked[N];
//		vector<int> nb[N];
//		for (int i = 0; i < r; i++) {
//			scanf("%d %d %d", &c1, &c2, &p);
//
//			nb[c1].push_back(c2);
//			nb[c2].push_back(c1);
//			e[c1][c2] = p;
//			e[c2][c1] = p;
//		}
//		scanf("%d %d %d",&S,&D,&T);
//		priority_queue<int, vector<int>, compare> dist;
//		priority_queue<int>result;
//
//		dist.push(S);
//
//		while (!dist.empty()){
//			c1=dist.top();
//			dist.pop();
//			checked[c1]=1;
//
//			for (vector<int>::iterator it=nb[c1].begin();it!=nb[c1].end();++it){
//				if (d[c1]>e[c1][*it]||!d[c1]){
//					temp=e[c1][*it];
//				}else{
//					temp=d[c1];
//				}
//				if (temp>d[*it]){
//					d[*it]=temp;
//				}
//				if (!checked[*it]){
//					dist.push(*it);
//				}
//			}
//		}
//		printf("%d\n\n",d[D]);
//	}
//}
