/*
 * uva108.cpp
 *
 *  Created on: May 3, 2015
 *      Author: quanghoang
 */
#include <iostream>
using namespace std;
int n;
int a[101] = { };
int getMaxSum() {
	int maxSoFar = -128, maxEndingHere = 0;
	int maxStartsCurrent = 0, maxEndsCurrent = 0;
	int maxStarts = 0, maxEnds = 0;
	int x = 0;

	for (int i = 0; i <= n; i++) {
		maxEndingHere = a[i] + maxEndingHere;

		if (maxEndingHere <= 0) { //if maxEnding<0, restart indexing
			maxEndingHere = 0;
			maxStartsCurrent = i + 1;
		}

		if (maxSoFar < maxEndingHere) { // new max found
			maxSoFar = maxEndingHere;
			maxEnds = i;
			maxStarts = maxStartsCurrent;
		}

	}
	return maxSoFar;
}
int main() {
	int m, s;
	int maxEntry = -128;
	cin >> n;
	long ar[101][101] = { };
	for (int i = 1; i <= n; i++) {
		s = 0;
		for (int j = 1; j <= n; j++) {
			//get prefix sum rows
			cin >> m;
			if (m > maxEntry) {
				maxEntry = m;
			}
			s += m;
			ar[i][j] = s;
		}
	}
	if (maxEntry <= 0) {
		cout << maxEntry << endl;
		return 0;
	}

	int maxSum = 0;
	int tempSum;

	for (int i = 0; i <= n; i++) {	// scan for max sum between column i and j;
		for (int j = i + 1; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				a[k] = ar[k][j] - ar[k][i];
			}
			tempSum = getMaxSum();
			if (maxSum < tempSum) {
				maxSum = tempSum;
			}
		}
	}
	cout << maxSum << endl;
	return 0;
}

