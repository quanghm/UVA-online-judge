/*
 * 10324.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int n, m = 1, t = 0, i, j, l;
	int hi, lo, mid;	//binaray search
	char ch = 32, current;
	while (ch != EOF) {
		m = 0; //counting number of chars
		current = 32;	//randomize characters
		vector<int> pattern;
		while ((ch = getchar()) == 48 || ch == 49) {
			if (ch != current) {	//new character;
				pattern.push_back(m);
				current = ch;
			}
			m++;
		}
		l = pattern.size() - 1;
//		printf("%d--\n", m);
//		printf("\n");
//		for (int i = 0; i <= l; i++) {
//			printf("%d ", pattern[i]);
//		}
//		printf("\n");
		if (m) {
			printf("Case %d:\n", ++t);
			scanf("%d", &n);getchar();
			while (n--) {
				scanf("%d %d", &i, &j);
				if (i > j) {
					lo = i;
					i = j;
					j = lo;
				}

				//binary search for base of i
				lo = 0, hi = l;
				while (hi > lo) {
					mid = (hi + lo + 1) / 2;
					if (i < pattern[mid]) {
						hi = mid - 1;
					} else {
						lo = mid;
					}
				}
				// check if i and j are in same range
				if (lo == l) {
					if (j < m || i == j) {
						printf("Yes\n");
					} else {
						printf("No\n");
					}
				} else if (j < pattern[lo + 1]) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			}
			while((ch=getchar())!=EOF&&ch!=10){
			}
		} else {
			break;
		}
	}
}
