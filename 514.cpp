/*
 * uva514.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n, m;
	int max, top;
	bool c;
	while ((cin >> n) && (n)) { // get the value n
		stack<int> station;
		stack<int> out;
		while (cin >> m && m) {
			max = n;
			out.push(m);
			for (int i = 1; i < n; i++) {
				cin >> m;
				out.push(m);
			}
			while (max) {
				// pop leaving cars
				while (!out.empty() && out.top() == max) {
					out.pop();
					max--;
				}

				// pop stationary cars
				while (!station.empty() && station.top() == max) {
					max--;
					station.pop();
				}

				// put non-max cars to stations
				while (!out.empty() && out.top() != max) {
					station.push(out.top());
					out.pop();
				}
				if (out.empty() || out.top() != max) {
					break;
				}
			}
			if (max) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
			}
		}
		cout << "\n";
	}
}

