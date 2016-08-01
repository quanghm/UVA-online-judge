/*
 * 10670.cppv7 6,
 *
 *  Created on: Jun 7, 2015
 *      Author: quang
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Compare {
public:
	bool operator()(pair<string, int> i, pair<string, int> j) {
		return (i.second > j.second
				|| (i.second == j.second && i.first > j.first));
	}
};
int main() {
	int t;
	int n, m, l, tm, tn;
	string s;
	char ch;
	long long a, b, c, d;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf("%d%d%d", &n, &m, &l);
		getchar();
		priority_queue<int, vector<pair<string, int> >, Compare> pq;
		for (int j = 0; j < l; j++) {
			s = "";
			while ((ch = getchar()) != 58) {
				s += ch;
			}
			a = 0;
			while ((ch = getchar()) != 44) {
				a = a * 10 + ch - 48;
			}
			b = 0;
			while ((ch = getchar()) != 10) {
				b = b * 10 + ch - 48;
			}
//			cout<<s<<":"<<a<<","<<b<<"\n";
			c = 0, tm = m, tn = n;
			while (tn>tm) {
				if (tm > (tn + 1) / 2) {	// less than half to reduce
					c+= (tn - tm) * a;
					break;
				} else {	// more than half to reduce
					d = (tn / 2) * a;	// price to reduce individual jobs
					if (d > b) {
						c += b;
						tn = (tn)/2;
					} else {
						c +=(tn-tm)*a;
						break;
					}
				}
			}
			pq.push(pair<string, int>(s, c));
		}
		printf("Case %d\n", i);
		while (!pq.empty()) {
			cout << pq.top().first << " " << pq.top().second << "\n";
			pq.pop();
		}
	}
}

