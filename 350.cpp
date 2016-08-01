/*
 * 350.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: quang
 */
#include<cstdio>
#include<map>
using namespace std;

int main() {
	int z, i, m, l;
	int c = 0; //case
	while (scanf("%d%d%d%d", &z, &i, &m, &l) != EOF && m) {
		c++;
		int s = 0; //step
		map<int, int> r;	// random numbers

		r[l] = s;
		while (1) {
			s++;
			l = (z * l + i) % m;
//			printf("%d::%d\n",s,l);
			if (r[l]) {
				printf("Case %d: %d\n", c, s - r[l]);
				break;
			} else {
				r[l]=s;
			}
		}
	}
}

