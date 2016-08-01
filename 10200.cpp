/*
 * 10200.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: qhoang
 */
#include <cstdio>
#include <vector>
#include<cmath>
using namespace std;

const int M = 10000;
int n = 100;
bool a[M] = { };
vector<int> pr;

bool isPrime(int i) {
	for (vector<int>::iterator it = pr.begin();
			it != pr.end() && *it <= sqrt(i); it++) {
		if (i % *it == 0) {
			return i == *it;
		}
	}
	return true;
}

int main() {
	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			for (int j = i * i; j < M; j += i) {
				a[j] = 1;
			}
		}
	}
	pr.push_back(2);
	for (int i = 3; i < M; i += 2) {
		if (!a[i]) {
			pr.push_back(i);
		}
	}
//	printf("%d---%d---\n",a[3],isPrime(9));
	int a, b;
	double s;
	int u[10001];
	u[0] = 1;
	for (int i = 1; i <= M; i++) {
		u[i] = (isPrime(i * i + i + 41)) ? u[i - 1] + 1 : u[i - 1];
//		printf("%d:%d--\n",i,u[i]);
	}
	while (scanf("%d%d", &a, &b) != EOF) {
		s = (a) ? (u[b] - u[a - 1]) * 100.0 : u[b] * 100.0;
		b=b-a+1;
		s=s/(b*1.0)+1e-10;
		printf("%.2lf\n", s);
	}
}

