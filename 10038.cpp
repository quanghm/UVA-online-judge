/*
 * 10038.cpp
 *
 *  Created on: May 21, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include<cstring>
using namespace std;

int main() {
	int n, current, next;
//	string line;
	bool flag;
	while (cin >> n) {
//		if (n == 1) {
//			cin >> current;
//			cout << "Jolly\n";
//		} else {
		bool d[3000] = { };
		cin >> current;
		d[0] = 1;
		flag = true;
		for (int i = 1; i < n; i++) {
			cin >> next;
			if (flag) {
				current -= next;
				if (current < 0) {
					current *= -1;
				}
				if (d[current] || current >= n) {
					flag = false;
				} else {
					d[current] = true;
				}
				current = next;
			}
		}
//		}
		if (flag) {
			cout << "Jolly\n";
		} else {
			cout << "Not jolly\n";
		}
	}
}

