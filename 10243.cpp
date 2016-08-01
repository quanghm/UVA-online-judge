/*
 * uva10243.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: Quang Hoang
 */
#include <iostream>
#include<vector>
#include<algorithm>
//#include<cstring>
//#include<queue>
using namespace std;

#define N 1001
vector<int> d;
bool compare(int i, int j) {
	return d[i] < d[j];
}
int main() {
	int n, ne, tv;

	while ((cin >> n) && n) {

		d.resize(n + 1, N);

		vector<int> index;
		int fe = 0, cv = n;
		vector<vector<int> > children(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> ne;
			d[i] = ne;
			index.push_back(i);
			for (int j = 0; j < ne; j++) {
				cin >> tv;
				children[i].push_back(tv);
			}
		}

		while (cv > 0) {
			sort(index.begin(), index.end(), compare);

			ne = index.front();
			if (d[ne]==0){
				d[ne]=N,fe++,cv--;
			} else 	if (d[ne] <= 2) {	//found a gallery with a single corridor
//				d[ne] = N, fe++, cv--;
				ne = children[ne][0];
				d[ne] = N, fe++, cv--;	// install exit at the adjacent gallery
				for (vector<int>::iterator it = children[ne].begin();
						it != children[ne].end(); it++) {
					if (d[*it] <= 2) {
						d[*it] = N, cv--;	//	this gallery is now safe
						for (vector<int>::iterator iit = children[*it].begin();
								iit != children[*it].end(); iit++) {
							if (d[*iit] != N) {
								d[*iit]--;
							}
						}
					}
				}

			}

		}
		cout << fe << "\n";
	}
}
//		//building graph
//		for (int i = 1; i <= n; i++) {
//			vector<int> v;	// list of edges
//			cin >> ne;
//			v.push_back(i);	// vertex index
//			d[i] = ne;	//	vertex degree
//			for (int j = 0; j < n; j++) {
//				cin >> ne;	// read the other vertices
//				v.push_back(ne);
//			}
//			edges.push(v);	// push the list
//		}
//		int count = 0;	// total
//		while (!edges.empty()) {
//			vector<int> v = edges.top();
//			edges.pop();
//			tv = v[0];	// current vertex
//			if (delEdges[tv]==0) {	// unvisited vertex
//				count++;
//				delEdges[tv] = 1;
//			for (int i=1;i<=d[tv]) {
//				d[i]--;
//			}
//		}
//	}
//}
//}
