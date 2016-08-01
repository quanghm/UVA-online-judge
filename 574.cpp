/*
 * 574.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>

using namespace std;
vector<int> d;
int n;

vector<vector<int> > findSum(int s, int i) {	//sum and index
	vector<vector<int> > u;
	vector<int>v;

	int t = i;
	while (t++ < n) {
		if (t == n || d[t] != d[i]) {
			break;
		}
	}
	if (t == n) {
		if (s % d[i] == 0 && (s / d[i] <= t - i)) {
			vector<int> v;
			for (int j = 0; j < s / d[i]; j++) {
				v.push_back(d[i]);
			}
			u.push_back(v);
		}
		return u;
	}
	int sum = s,r=d[i];

	for (int j = i; j <= t && sum >= 0; j++) {
		vector<vector<int> > w = findSum(sum, t);
		for (vector<vector<int> >::iterator it = w.begin(); it != w.end();
				it++) {
			v = *it;
			for (int k = i; k < j; k++) {
				v.push_back(r);
			}
			u.push_back(v);

		}
		sum -= d[i];
	}

	return u;
}
int main() {
	int s;
	while (scanf("%d%d", &s, &n) != EOF && n) {
		d.clear();
		d.resize(n);
		for (vector<int>::iterator it = d.begin(); it != d.end(); it++) {
			scanf("%d", &(*it));
		}
		printf("Sums of %d:\n", s);
		vector<vector<int> > u = findSum(s, 0);
		if (u.size()) {
			for (vector<vector<int> >::reverse_iterator it = u.rbegin();
					it != u.rend(); it++) {
				vector<int>::reverse_iterator ut = it->rbegin();
				printf("%d", *ut);
				while (++ut != it->rend()) {
					printf("+%d", *ut);
				}
				printf("\n");
			}
		} else if (u.size()) {
			printf("%d\n", u[0][0]);
		} else {
			printf("NONE\n");
		}
	}
}

