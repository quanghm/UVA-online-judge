/*
 * 10131.cpp
 *
 *  Created on: Jun 20, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> w;
vector<int> s;
bool dumper(int i, int j) {
	return s[i] > s[j] || (s[i] == s[j] && w[i] < w[j]);
}

int main() {
	vector<int> index;

	int wt, st, i = 0;

	w.push_back(0);
	s.push_back(0);
	while (scanf("%d %d", &wt, &st) != EOF) {
		w.push_back(wt), s.push_back(st);
		index.push_back(++i);
	}
	sort(index.begin(), index.end(), dumper);

//	for (vector<int>::iterator it = index.begin(); it != index.end(); it++) {
//		printf("%d:%d %d\n", *it, w[*it], s[*it]);
//	}

	vector<int> m(i, 1);	//max length ending at j
	vector<int> p(i, -1);	//previous position

	st=0;
	for (int j = i-1; j >=0; j--) {
		for (int k = i-1; k > j; k--) {
//			printf("%d:%d::\n",index[k],index[j]);
			if (w[index[k]] > w[index[j]] && s[index[k]] < s[index[j]]
					&& m[k] >= m[j]) {
				m[j] = m[k] + 1;
				p[j] = k;
			}

		}
		if (m[j] > st) {
			wt = j;
			st=m[j];
		}
	}
//	int l = 0;	// max length
//	int hi = 1, lo = 0, mid;
//
//	for (int j = 0; j < i; j++) {
//		hi = l, lo = 1;
//		while (hi >= lo) {
//			mid = (hi + lo + 1) / 2;
//			if (w[index[m[mid]]] < w[index[j]]
//					&& s[index[j]] != s[index[m[mid]]]) {
//				lo = mid + 1;
//			} else {
//				hi = mid - 1;
//			}
//		}
//		m[lo] = j;
//		p[j] = m[lo - 1];
//		if (lo > l) {
//			l = lo;
//		}
//	}
//	vector<int> a;
//	hi = m[l];
//	for (int j = l - 1; j >= 0; j--) {
//		a.push_back(index[hi]);
//		hi = p[hi];
//	}
	printf("%d\n", m[wt]);
	while (wt>-1) {
		printf("%d\n", index[wt]);
		wt = p[wt];
	}
}

