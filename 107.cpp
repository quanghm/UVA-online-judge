/*
 * uva107.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: Quang Hoang
 */
#include <iostream>
#include <math.h>
#include<algorithm>

using namespace std;
int main() {
	int m, n, d, t;
	float e;
	while ((cin >> m >> n) && (m)) {
		if (n == 1) {
			cout << log2(m) <<" "<< m * 2 - 1 << endl;
		} else {
			d = __gcd(m - 1, n);
			t = 2;
			while (t < d) {
				if (d % t == 0) {
					e = log(m) / log(t + 1) - log(n) / log(t);
					if (e < 0.0001 && e > -0.00001) {

						break;
					}
				}
				t++;
			}
			cout << (n - 1) / (t - 1) << " " << m * (t + 1) - n * t<<endl; //N found
		}
	}
	return 0;
}
