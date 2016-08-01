/*
 * 11235.cpp
 *
 *  Created on: May 27, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
#include<map>
#include<vector>
using namespace std;

int main() {
	int n, q;
	int i, j;
	while (scanf("%d", &n) != EOF && n) {
		scanf("%d", &q);
		vector<int> num(n + 1); // values
		vector<int>::iterator nit = num.begin();
		map<int, int> v;	// frequence
		map<int, int> s;	//start index
		for (i = 1; i <= n; i++) {
			++nit;
			scanf("%d", &num[i]);
			v[*nit]++;
			if (s[*nit] == 0) {
				s[*nit] = i;
			}
		}
		while (q--) {
			scanf("%d%d", &i, &j);
			priority_queue<int> f;
			map<int, int>::iterator it = v.begin();
			i--;
			while (it != v.end()) {
				i -= it->second;
				j -= it->second;
				if (i < 0) {
					f.push(-i);
					it++;
					break;
				} else {
					it++;
				}
			}
			while (it != v.end()) {
				j -= it->second;
				if (j < 0) {
					f.push(it->second + j);
					break;
				} else {
					f.push(it->second);
					it++;
				}
			}
			printf("%d\n", f.top());
		}
	}
}

