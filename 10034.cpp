/*
 * 10034.cpp
 *
 *  Created on: Jun 20, 2015
 *      Author: quang
 */
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include <iomanip>      // std::setprecision

using namespace std;

vector<double> xs;
vector<double> ys;

double dist(int i, int j) {
	double dx = xs[i] - xs[j];
	double dy = ys[i] - ys[j];
	return sqrt(dx * dx + dy * dy);
}

class edge {
public:
	int s, t;
	double l;
	edge(int s, int t) :
			s(s), t(t) {
		l = dist(s, t);
	}
};

class compare {
public:
	bool operator()(edge e1, edge e2) {
		return e1.l > e2.l;
	}
};

int main() {
	int c, n, count, visited, start, end;
	double x, y, s;
	cin >> c;
	cout << fixed << setprecision(2);
	while (c--) {
		cin >> n;
		if (n == 1) {
			cin >> x >> y;
			cout << "0.00\n";
		} else {
			vector<bool> visited(n, 0);
			priority_queue<int, vector<edge>, compare> gr;
			count = n - 1, s = 0;
			xs.clear(), ys.clear();
			for (int i = 0; i < n; i++) {
				cin >> x >> y;
				xs.push_back(x), ys.push_back(y);
			}
			start = 0;
			while (count--) {
				for (int j = 0; j < n; j++) {
					if (!visited[j] && j != start) {
						gr.push(edge(start, j));
					}
				}
				visited[start] = 1;
				while (!gr.empty() && visited[gr.top().s] && visited[gr.top().t]) {
					gr.pop();
				}
				s += gr.top().l;
				start = visited[gr.top().s] ? gr.top().t : gr.top().s;
				gr.pop();
			}
			cout << s << "\n";
		}
		if (c) {
			cout << "\n";
		}
	}
}

