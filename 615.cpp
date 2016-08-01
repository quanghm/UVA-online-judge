/*
 * 615.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: quang
 */
#include<cstdio>
#include<map>

using namespace std;

int main() {
	int k = 0, m, n;
	while (scanf("%d %d", &m, &n) && m >= 0) {
		map<int, int> tree;
		int nt = 0;
		bool flag = 1;
		while (m && n) {
//			printf("%d--%d:\n",m,n);
//			if (m == n) {
//				flag = false;
//			}
			if (flag) {
				if (tree[m] == 0) {	//m is a new node
					nt++;
					tree[m] = m;
				}
				if (tree[n] == 0) {	// n is a new node
					tree[n] = tree[m];
				} else if (tree[n] == n&&tree[m]!=n) {	// n is the root of another existing tree
					nt--;
					for (map<int, int>::iterator it = tree.begin();
							it != tree.end(); it++) {
						if (it->second == n) {
							it->second = tree[m];
						}
					}
				} else {	// n is already in another tree - not a tree
					flag = 0;
				}
			}
//			printf("____\n");
//			for (map<int, int>::iterator it = tree.begin(); it != tree.end();
//					it++) {
//				printf("%d:%d\n", it->first, it->second);
//			}
//			printf("____\n");
			scanf("%d %d", &m, &n);
		}
//		printf("____\n");
//		for (map<int, int>::iterator it = tree.begin(); it != tree.end();
//				it++) {
//			printf("%d:%d\n", it->first, it->second);
//		}
//		printf("____\n");
		if (flag && nt <2 ) {
			printf("Case %d is a tree.\n", ++k);
		} else {
			printf("Case %d is not a tree.\n", ++k);
		}
	}
}
