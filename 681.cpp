/*
 * 681.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#define max 100000
using namespace std;

vector<pair<int, int> > pts;
int start;
double ix, iy;
double dot(int u, int v) {	//dot product
	double dx = pts[v].first - pts[u].first;
	double dy = pts[v].second - pts[u].second;
	double result = dx * ix + dy * iy;
	result /= sqrt(dx * dx + dy * dy);
	return result;
}
class compare {
public:
	bool operator()(int i, int j) {
		return (dot(start, i) < dot(start, j));
	}
};
class cHull {
public:
	bool operator()(int i, int j) {
		return (pts[i].second > pts[j].second
				|| (pts[i].second == pts[j].second
						&& pts[i].first > pts[j].first));
	}
};
int main() {
	int k, n, x, y, top, count;
	double dx, dy, l;

	scanf("%d", &k);
	printf("%d\n", k);
	while (k--) {	// each test case
		pts.clear();
		scanf("%d", &n);
		n--;	// actual number of vertices
		start = 0, iy = max, ix = max;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			if (y < iy || (y = iy && x < ix)) {
				start = i, iy = y, ix = x;
			}
			pts.push_back(pair<int, int>(x, y));	// push the next point
		}
		scanf("%d %d %d", &x, &y, &ix);	// get rid of extra data

	}
}
