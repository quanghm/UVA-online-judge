/*
 * 10394.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int N = 20000000;
int n = 4474;
bool a[N] = { };

vector<int> pr;
bool isPrime(int i) {
	return !a[i];
//	for (vector<int>::iterator it = pr.begin();
//			it != pr.end() && *it <= sqrt(i); it++) {
//		if (i % *it == 0) {
//			return i == *it;
//		}
//	}
//	return true;
}
int main() {
	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < N; j += i) {
				a[j] = true;
			}
		}
	}
//	pr.push_back(2);
//	for (int i = 3; i < N; i += 2) {
//		if (!a[i]) {
//			pr.push_back(i);
//		}
//	}
	vector<int> twin;
	n = 100000;
	int p = 3;
	while (n) {
		if (isPrime(p) && isPrime(p + 2)) {
			twin.push_back(p);
			n--;
		}
		p += 2;
	}
//	printf("done:%d",p);

	while (scanf("%d", &n) != EOF) {
		p = twin[n - 1];
		printf("(%d, %d)\n", p, p + 2);
	}
}

