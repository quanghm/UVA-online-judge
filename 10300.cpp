/*
 * 10300.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main() {
	int n, f;
	int s, a, ef;
	long long cost;

	scanf("%d", &n);
	while (n--) {
		cost = 0;
		scanf("%d", &f);
		while (f--) {
			scanf("%d %d %d", &s, &a, &ef);

			if (a) {
				cost += s * ef;
			}

		}
		printf("%lld\n", cost);
	}
}
