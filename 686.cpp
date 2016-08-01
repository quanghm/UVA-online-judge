/*
 * uva686.cpp
 *
 *  Created on: May 5, 2015
 *      Author: quanghoang
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	int n = 32768;
	bool a[32768] = { 0 }; // if i is check
	int i = 1, s = 0;
	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		for (int j = 2 * i; j < n; j += i) { // kill multiple of i
			a[j] = true;
		}
	}

	while ((cin >> n) && (n)) {
		if ((n > 32768) || (n < 4)) {
			cout << n << "is out of range: 5<n<1000000";
		}
		if (n<8){
			cout << "1" << endl;
		} else {
			s = 0;
			i = n - 2;
			while ((i--) && (i >= n/ 2)) {
				if (!(a[i] || a[n - i])) {
					s++;
				}
			}
			cout<<s<<endl;
		}
	}

}
