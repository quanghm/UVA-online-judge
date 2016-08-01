/*
 * 11827.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, m, a, b, temp;
	string line;
	cin >> n;
	getline(cin, line);
	while (n--) {
		vector<int> nums;
		priority_queue<int> gcd;
		getline(cin, line);
		istringstream iss(line);
		while (iss>>m) {
			for (vector<int>::iterator it = nums.begin(); it != nums.end();
					it++) {
				a = m;
				b = *it;
				while (a) {	// find gcd by euclidean
					temp = a;
					a = b % a;
					b = temp;
				}
				gcd.push(b);
			}
			nums.push_back(m);
		}
		printf("%d\n", gcd.top());
	}
}

