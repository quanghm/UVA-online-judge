/*
 * 10041.cpp
 *
 *  Created on: May 18, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int r, temp, total;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &r);
		vector<int> s;
		total = 0;
		for (int i = 0; i < r; i++) {
			scanf("%d", &temp);
			s.push_back(temp);
		}
		sort(s.begin(), s.end());

		for (int i = 0; i < r / 2; i++) {
			total += (s[r - i - 1] - s[i]);
		}
		printf("%d\n", total);
	}
}

