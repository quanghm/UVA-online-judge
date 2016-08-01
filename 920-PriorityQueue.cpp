/*
 * 920.cpp
 *
 *  Created on: May 15, 2015
 *      Author: qhoang
 */
#include <iostream>
#include<stdio.h>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

class point {
public:
	int x, y;
	point(int i, int j) :
			x(i), y(j) {
	}
	point() :
			x(0), y(0) {
	}
};

class isLeft {
public:
	//isLeft()
	bool operator()(point i, point j) {
		return (i.x < j.x);
	}
};

int main() {
	int c, n, xx, yy, dx,dy;
	int rx, ry;	//right point;
	double s;
	cin >> c;

	while (c--) {
		cin >> n;
		if (!n) {
			cout << "0.00\n";
		} else {
			priority_queue<int, vector<point>, isLeft> points;
			while (n--) {
				cin >> xx >> yy;
				points.push(point(xx, yy));
			}
			s = 0;
			//pop the right most point.
			rx = points.top().x;
			yy = points.top().y;
			ry=yy;
			points.pop();

			while (!points.empty()) {
				while (!points.empty() && points.top().y <= yy) {// search for next highest point;
					rx = points.top().x;
					ry = points.top().y;
					points.pop();
				}
				if (points.empty()) {
					break;
				}

				point u=points.top();
				//points.pop();
				dx = u.x-rx;dy=u.y-ry;
				s+=sqrt(dx*dx+dy*dy)*(u.y-yy)/dy;
				yy=u.y;
			}

			printf("%.2f\n",s);
		}
	}
}
