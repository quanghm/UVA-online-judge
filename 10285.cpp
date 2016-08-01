/*
 * 10285.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: qhoang
 */
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int h[102][102] = { };
int p[101][101] = { };
class higher {
public:
	bool operator()(pair<int, int> i, pair<int, int> j) {
		return h[i.first][i.second] > h[j.first][j.second];
	}
};
int main() {
	int n, r, c, i, j, max, tm;
	string s;
	cin >> n;
	while (n--) {
		max = 0;
		memset(h, 1, sizeof(h));
		memset(p, 0, sizeof(p));
		priority_queue<int, vector<pair<int, int> >, higher> heights;
		priority_queue<int>path;
		cin >> s >> r >> c;
		for (i = 1; i <= r; i++) {
			for (j = 1; j <= c; j++) {
				cin >> h[i][j];
				heights.push(pair<int, int>(i, j));
			}
		}
		while (!heights.empty()) {
			i = heights.top().first, j = heights.top().second;
			heights.pop();
			tm = (h[i - 1][j] < h[i][j])? p[i - 1][j]:0;
			if (h[i + 1][j] < h[i][j]) {
				tm = (p[i + 1][j] > tm) ? p[i + 1][j] : tm;
			}
			if (h[i][j - 1] < h[i][j]) {
				tm = (p[i][j - 1] > tm) ? p[i][j - 1] : tm;
			}
			if (h[i][j + 1] < h[i][j]) {
				tm = (p[i][j + 1] > tm) ? p[i][j + 1] : tm;
			}
			p[i][j] = tm + 1;
//			cout<<i<<":"<<j<<"="<<tm<<"\n";
			path.push(p[i][j]);
		}
		cout<< s<<": "<<path.top()<<"\n";
	}
}

