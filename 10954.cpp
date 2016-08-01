/*
 * uva10954.cpp
 *
 *  Created on: May 3, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include <list>

using namespace std;

list<int> num;
int s;
void insert(int i) {
	list<int>::iterator it = num.begin();

	while (i > *it && it != num.end()) { //find the last position with value < m.
		it++;
	}
	num.insert(it, i);	//insert at that position
}

int main() {
	int n, m;
	long long c;

	while ((cin >> n) && (n)) {
		c = 0;
		s = 1;

		cin >> m;	//read first number
		num.push_back(m);	//push to list

		for (int i = 1; i < n; i++) {	// insert other numbers into list
			cin >> m;
			insert(m);
		}
		while (1) {	//more than one number in queue
			//pop two first numbers
			m = *(num.begin());
			num.erase(num.begin());
			m += *(num.begin());
			num.erase(num.begin());
			c += m;

			if (num.empty()) {	// queue is empty, display cost
				cout << c << endl;
				break;
				//num.erase(num.begin());
			} else {	//queue not empty
				insert(m);
			}
		}
	}
}
