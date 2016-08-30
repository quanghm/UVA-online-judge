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
		char m[32][82] = { };	//maze map
		int i = 1, j;
		queue<pair<int, int> > sp;
		
		// read next maze line by line until ;----; is read
		while (getline(cin, line) && line[0] != 95) {
			j=1;
			for (string::iterator it=line.begin(); 
                                it!=line.end(); ++it, ++j) {
				if (*it == '*') {	//source point
					m[i][j] = 32;
					sp.push(pair<int, int>(i, j));
				} else {
					m[i][j] = *it;
				}
			}
			i++;
		}
		while (!sp.empty()) {
			i = sp.front().first, j = sp.front().second;
			sp.pop();
			if (m[i][j] == '#') continue;
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
		for (i = 1; i < 31 && m[i][1]; i++) {
			for (j = 1; j < 81 && m[i][j]; j++) {
				cout << m[i][j];
			}
			cout << "\n";
		}
		cout << line << "\n";
	}
}
