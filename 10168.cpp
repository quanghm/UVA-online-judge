/*
 * 10168.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>

using namespace std;

const int M = 10000001;

bool a[M] = { };
//vector<int>p;
int n = 3163;

int main() {
	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < M; j += i) {
				a[j] = 1;
			}
		}
	}

	while (scanf("%d", &n) != EOF) {
		if (n > 9) {
			if (n % 2) {
				printf("2 3 ");
				n -= 5;
			} else {
				printf("2 2 ");
				n -= 4;
			}
			for (int i = 3; i <= n / 2; i+=2) {
				if (!(a[i]||a[n-i])){
					printf("%d %d\n",i,n-i);
					break;
				}
			}
		}
		else if (n==9){
			printf("2 2 2 3\n");
		} else if (n==8){
			printf("2 2 2 2\n");
		} else {
			printf("Impossible.\n");
		}

	}
}

