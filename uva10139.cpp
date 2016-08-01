/*
 * uva10139.cpp
 *
 *  Created on: May 19, 2015
 *      Author: quang
 */
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
const int m = 46342;
int main() {
	int n =216;
	bool a[m] = { 0 }; // if i is check
	int i = 1;
	vector<int> primes;
	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		for (int j = i * i; j < m; j += i) { // kill multiple of i
			a[j] = true;
		}
	}

	for(i=2;i<m;i++){
		if (!a[i]){primes.push_back(i);}
	}


}



