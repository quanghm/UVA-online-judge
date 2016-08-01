/*
 * 294.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int N = 31622;
int m, n = 179;
bool a[N] = { };
vector<int> pr;
int nod(int m) {
	int s = 1;
	int t = 0;
	for (vector<int>::iterator it = pr.begin(); it != pr.end() && *it < m;
			it++) {
		if (m % *it == 0) {
			t = 1;
			while (m % *it == 0) {
				t++;
				m /= *it;
			}
			s *= t;
		}
	}
	if (m > 1) {
		s *= 2;
	}
	return s;
}
class compare {
public:
	bool operator()(pair<int, int> i, pair<int, int> j) {
		return (i.first < j.first || (i.first == j.first && i.second > j.second));
	}
};
int main() {
	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < N; j += i) {
				a[j] = 1;
			}
		}
	}
	pr.push_back(2);
	for (int i = 3; i < N; i += 2) {
		if (!a[i]) {
			pr.push_back(i);
		}
	}
//	printf("%d--%d", nod(12), nod(16));
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &m, &n);
		priority_queue<int, vector<pair<int, int> >, compare> v;
		for (int i = m; i <= n; i++) {
			v.push(pair<int, int>(nod(i), i));

		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", m, n,
				v.top().second, v.top().first);
	}
}

