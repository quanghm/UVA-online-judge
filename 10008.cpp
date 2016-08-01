/*
 * uva10008.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <vector>

using namespace std;

int ar[26];
bool compare(char i, char j) {

	return (ar[int(i - 65)] > ar[int(j - 65)]
			|| (i < j && ar[int(i - 65)] == ar[int(j - 65)]));
}
int main() {
	int n;
	cin >> n;
	string line;
	vector<char> v;
	char c;
	for (c = 65; c <= 90; c++) {
		v.push_back(c);
	}

	while(getline(cin, line)){
		for (string::iterator it = line.begin(); it != line.end(); ++it) {
			if ((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122)) {
				ar[toupper(*it) - 65]++;
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	for (vector<char>::iterator it = v.begin(); it <= v.end() && ar[(*it - 65)];
			it++) {
		cout << *it << " " << (ar[int(*it - 65)]);
		cout << endl;
	}

}

