/*
 * uva10004.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quang
 */
#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, l;
	int a, b;
	while ((cin >> n) && (n)) {
		cin >> l;
		queue<int> e[200];
		int c[200]={};

		for (int i = 0; i < l; ++i) {
			cin >> a >> b;
			e[a].push(b);
			e[b].push(a);
		}
		int j = 0;
		queue<int> cv;
		int temp;
		cv.push(0);
		int color = 0;
		c[0] = 1;
		bool b = false;	//bicolorable
		while (!cv.empty()) {	// start coloring
			j = cv.front();
			cv.pop();
			color = 3 - c[j];	// change color

			while (!e[j].empty()) {	// for each temp connected to j
				temp = e[j].front();
				e[j].pop();
				if ((c[temp]) && c[temp] == c[j]) {
					// if temp has same color with j
					b = true;
					break;
				} else {
					// temp doesn't have a color - paint it
					if (c[temp] == 0) {
						c[temp] = color;
						cv.push(temp);
					}
					// else - temp has opposite color to j: no actions
				}
			}
			if (b) {	// if conflict found
				break;
			}
		}
		if (b) {
			cout << "NOT BICOLORABLE." << endl;
		} else {
			cout << "BICOLORABLE." << endl;
		}
	}
}

