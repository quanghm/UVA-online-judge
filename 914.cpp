/*
 * 914.cpp
 *
 *  Created on: May 22, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int M = 1000000;
bool isLess(pair<int, int> p, pair<int, int> q) {
	return (p.second < q.second);
}
int main() {
	int N = 1000;
	bool p[M] = { };
	bool flag;

	vector<int> primes;
	for (int i = 2; i < N; i++) {
		if (!p[i]) {
			for (int j = i * i; j < M; j += i) {
				p[j] = 1;
			}
		}
	}
	primes.push_back(2);
	for (int i = 3; i < M; i += 2) {
		if (!p[i]) {
			primes.push_back(i);
		}
	}

	int l, u;
	int max, pos, temp;
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &l, &u);
		flag = false;
		max = 0;

		vector<int>::iterator it = primes.begin();
		while (it != primes.end() && *it < l) {
			it++;
		}
		if (it == primes.end() || *it > u) { //less than 1 prime
			printf("No jumping champion\n");
		} else {
			map<int, int> jumps;
			do {
				pos = *it;
				it++;
				if (it == primes.end() || *it > u) {
					break;
				}
				temp = *it - pos;
				jumps[temp]++;
			} while (1);
			if (jumps.size()) {
				priority_queue<pair<int, int> > champ;
				for (map<int, int>::iterator it = jumps.begin();
						it != jumps.end(); it++) {
					champ.push(pair<int, int>(it->second, it->first));
				}
				pos = champ.top().first;
				max = champ.top().second;
				champ.pop();
				if (champ.empty() || pos > champ.top().first) {
					printf("The jumping champion is %d\n", max);
				} else {
					printf("No jumping champion\n");
				}
			} else {
				printf("No jumping champion\n");
			}
		}
	}
}
