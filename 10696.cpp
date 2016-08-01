/*
 * uva10696.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quanghoang
 */
#include <iostream>
using namespace std;
int main() {
	int n;

	while ((cin >> n) && (n)) {
		cout << "f91(" << n << ") = " << ((n > 101) ? (n - 10) : (91) )<< endl;
	}
}

