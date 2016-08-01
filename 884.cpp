/*
 * 884.cpp
 *
 *  Created on: May 15, 2015
 *      Author: qhoang
 */
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
const int m = 1001;
int main() {
	int n = 32;
	int a[1000001] = { }; // if i is composite
	int i = 1, s;

	//prime list
	vector<int> p;
	vector<int>::iterator it;

	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		// i is now a new prime;
		for (int j = i * i; j < m; j += i) { // kill multiple of i
			a[j] = true;
		}
	}
	// create vector of primes
	i = 1;
	while (++i < m) {
		if (!a[i]) {
			p.push_back(i);
		}
	}

	// indexing number of prime factors
	a[0]=0;a[1]=0;
	for (i=2;i<1000001;i++){
		a[i]=a[i-1];
		it=p.begin();
		n=i;
		while (it!=p.end()&&*it<n){
			while (n%(*it)==0){
				a[i]++;
				n/=*it;
			}
			it++;
		}
		if (n>1){
			a[i]++;
		}
	}

	while (cin >> n) {
		cout<<a[n]<<"\n";
	}

}
