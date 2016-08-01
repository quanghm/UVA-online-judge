/*
 * 10928.cpp
 *
 *  Created on: May 30, 2015
 *      Author: quanghoang
 */

#include<cstdio>
#include<queue>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;

class Compare {
public:
	bool operator()(pair<int, int> i, pair<int, int> j) {
		return (i.first > j.first || (i.first == j.first && i.second > j.second));
	}
};
int main() {
	int N, p, t, u;
	string line;

	cin >> N;
	//getline(cin,line);

	while (N--) {
		cin >> p;
		getline(cin, line);
		priority_queue<int, vector<pair<int, int> >, Compare> ut;
		for (int i = 1; i <= p; i++) {
			getline(cin, line);
			istringstream iss(line);
			t = 0;
			while (iss >> u) {
				t++;
			}
			ut.push(pair<int, int>(t, i));
		}
//		sort(ut.begin(), ut.end(), compare);
		u = ut.top().first;
		while (1) {
			cout << ut.top().second;
			ut.pop();
			if (ut.empty() || u != ut.top().first) {
				cout << "\n";
				break;
			} else {
				cout << " ";
			}
		}
	}
}

