/*
 * 11626.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
const double INF = 2e10;
using namespace std;
double ma, Ma;
vector<pair<double, double> > hull;
vector<pair<double, double> > a;	// angles

//class Compare {
//public:
//	bool operator()(int i, int j) {
//		return (a[i] > a[j] || (a[i] == a[j] && hull[i].first > hull[j].first));
//	}
//};
bool isLess(int i, int j) {
return  a[i].first < a[j].first

			|| (a[i].first == a[j].first && a[i].first == ma
					&& a[i].second < a[j].second)
			|| (a[i].first == a[j].first && a[i].first == Ma
					&& a[i].second > a[j].second);
}
int main() {
	int t, n, min, c;
	double x, y, dx, dy;
	char ch;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int min = 0, c = 0;
		double mx = INF, my = INF;
		ma = 4, Ma = -1;
		hull.clear();
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf %c", &x, &y, &ch);
			if (ch == 89) {
				hull.push_back(pair<double, double>(x, y));
				if (x < mx || (x == mx && y < my)) {
					mx = x, my = y, min = c;
				}
				c++;
			}
		}
		// c= total points on convext hull
		printf("%d\n", c);
		hull.erase(hull.begin() + min);
		printf("%.0lf %.0lf\n", mx, my);
		c--;
		a.clear();
		vector<int> b;	//index order
		for (int i = 0; i < c; i++) {
			dx = hull[i].first - mx, dy = hull[i].second - my;
			dx = sqrt(dx * dx + dy * dy);
			dy = acos(-dy / dx);
			if (dy > Ma) {
				Ma = dy;
			}
			if (dy < ma) {
				ma = dy;
			}
			a.push_back(pair<double, double>(dy, dx));
			b.push_back(i);
		}
		sort(b.begin(), b.end(), isLess);
		for (vector<int>::iterator it = b.begin(); it != b.end(); it++) {
			printf("%.0lf %.0lf\n", hull[*it].first, hull[*it].second);
		}
//		while (!b.empty()) {
//			min = b.top();
//			printf("%.0lf %.0lf\n", hull[min].first, hull[min].second);
//			b.pop();
//		}
	}
}
