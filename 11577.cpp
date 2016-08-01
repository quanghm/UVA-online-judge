/*
 * 11577.cpp
 *
 *  Created on: May 28, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool comparePair(pair<int, char> a, pair<int, char> b) {
	if (a.first < b.first) {
		return true;
	} else if (a.first == b.first) {
		return (a.second > b.second);
	} else {
		return false;
	}
}
int main() {
	int t;
	string line;
	cin >> t;
	getline(cin, line);

	while (t--) {
		getline(cin, line);
		map<char, int> f;
		for (string::iterator it = line.begin(); it != line.end(); it++) {
			if (isalpha(*it)) {
				f[tolower(*it)]++;
			}
		}
		vector<pair<int, char> > out;
		//priority_queue<pair<int, char> >pq;
		for (map<char, int>::iterator it = f.begin(); it != f.end(); it++) {
			out.push_back(pair<int, char>(it->second, it->first));
		}
		sort(out.begin(), out.end(), comparePair);
		int max = (out.back()).first;
		for (vector<pair<int, char> >::reverse_iterator it = out.rbegin();
				it != out.rend() && (it->first == max); it++) {
			cout << it->second;
		}
		cout << "\n";
	}
}
