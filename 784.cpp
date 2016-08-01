/*
 * 784.cpp
 *
 *  Created on: May 15, 2015
 *      Author: quanghoang
 */
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int INF = 100000;
int main() {
	int n, l;
	cin >> n;
	string line;
	getline(cin, line);
	while (n--) {
		char m[32][82] = { };	//maxe map
		int i = 0, j;
		queue<pair<int, int> > sp;
		while (getline(cin, line) && line[0] != 95) {
			l = line.length();
			for (j = 0; j < l; j++) {
				if (line[j] == 42) {	//source point
					m[i][j] = 32;
					sp.push(pair<int, int>(i, j));
				} else {
					m[i][j] = line[j];
				}
			}
			i++;
		}
		while (!sp.empty()) {
			i = sp.front().first, j = sp.front().second;
			sp.pop();
			m[i][j] = 35;
			if (m[i - 1][j] == 32) {
				sp.push(pair<int, int>(i - 1, j));
			}
			if (m[i + 1][j] == 32) {
				sp.push(pair<int, int>(i + 1, j));
			}
			if (m[i][j - 1] == 32) {
				sp.push(pair<int, int>(i, j - 1));
			}
			if (m[i][j + 1] == 32) {
				sp.push(pair<int, int>(i, j + 1));
			}
		}
		for (i = 0; i < 30 && m[i][1]; i++) {
			for (j = 0; j < 80 && m[i][j]; j++) {
				cout << m[i][j];
			}
			cout << "\n";
		}
		cout << line << "\n";
	}
}
