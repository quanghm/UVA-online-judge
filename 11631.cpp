/*
 * 11631.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>

using namespace std;

class triple {
public:
	int x, y, z;
	triple(int x, int y, int z) :
			x(x), y(y), z(z) {
	}
	triple() :
			x(), y(), z() {

	}
};
class compare {
public:
	bool operator()(triple i, triple j) {
		return i.z > j.z;
	}
};

int main() {
	int m, n, a, b, c, s;
	while (scanf("%d %d", &m, &n) != EOF && m) {
		if (n) {
			s = 0;
			vector<triple> edges(n);
			vector<bool> visited(m);
			for (int i = 0; i < n; i++) {
				scanf("%d %d %d", &a, &b, &c);
				edges[i] = triple(a, b, c);
				s += c;
			}
			sort(edges.begin(), edges.end(), compare);
			a = edges[0].x, b = edges[0].y, s -= edges[0].z;
			visited[a] = 1, visited[b] = 1;
		} else {
			printf("0\n");

		}
	}
}
