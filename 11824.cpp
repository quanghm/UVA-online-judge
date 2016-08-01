/*
 * 11824.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int c;
	int n;
	int s = 0; //sum
	bool flag;
	int p;

	scanf("%d", &c);

	while (c--) {
		vector<int> lands;
		while (scanf("%d", &n) != EOF) {
			if (n) {
				lands.push_back(n);
			} else {
				//input ends. Compute
				sort(lands.begin(), lands.end());
				s = 2500000;
				n = lands.size(); //power
				flag=true;

				for (vector<int>::iterator it = lands.begin();
						it != lands.end(); it++) {
					//compute power
					p = 1;
					for (int i = 0; i < n; i++) {
						if (*it > s / p) {
							flag = false;
							break;
						}
						p *= *it;
					}

					if (p > s) {
						flag = false;
						break;
					} else {
						n--;
						s -= p;
					}
				}

				if (flag) {
					s = 2 * (2500000 - s);
					printf("%d\n", s);
				} else {
					printf("Too expensive\n");
				}
				break;	//move to next case;
			}
		}
	}
}

