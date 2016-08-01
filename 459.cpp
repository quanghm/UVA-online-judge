/*
 * 459.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: quang
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int c, g,temp;
	char max;
	string l;
	cin >> c >> l;
	while (c--) {
		max = l[0];	//max char
		g = max - 64;
		vector<int>sub;
		for (char i = 'A'; i <=max; i++) {
			sub.push_back(i);
		}

		while (cin >> l && l.length() == 2) {
//			cout<<l<<"--\n";
			if (sub[l[0] - 65] != sub[l[1] - 65]) {
				temp=sub[l[0]-65];
				for (vector<int>::iterator it=sub.begin();it!=sub.end();it++) {
					if (*it== temp) {
						*it = sub[l[1] - 65];
					}
				}
				g--;
			}
		}
		cout << g << ((c) ? "\n\n" : "\n");
	}
}

