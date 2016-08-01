/*
 * 10000.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: quang
 */
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;
const int N = 101;

class compare {
public:
	bool operator()(pair<int, int> i, pair<int, int> j) {
		return (i.first > j.first || (i.first == j.first && i.second < j.second));
	}
};
int main() {
	int t = 0, n, s, p, q;
	while (scanf("%d", &n) != EOF && n) {
		scanf("%d", &s);
		vector<int> dist(n+1);
//		bool a[N][N] = { };
		vector<vector<int> > children(n+1);
		priority_queue<int, vector<pair<int, int> >, compare> pq;
		pq.push(pair<int, int>(0, s));
		while (scanf("%d %d", &p, &q) && p) {
//			a[p][q] = 1;
			children[p].push_back(q);
		}
		while (!pq.empty()) {
			p = pq.top().first;	// distant
			q = pq.top().second; // current node
			pq.pop();
//			for (int i = 1; i <= n; i++) {
//				if (a[q][i]) {
//					pq.push(pair<int, int>(p + 1, i));
//				}
//			}
			for (vector<int>::iterator it=children[q].begin();it!=children[q].end();it++){
				pq.push(pair<int,int>(p+1,*it));
			}
		}
		printf(
				"Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
				++t, s, p, q);
	}
}

