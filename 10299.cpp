/*
 * 10299.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;

const int N = 31623;
int main() {
	int n, phi;
	bool a[N] = { };

	for (int i = 2; i < 179; i++) {
		if (!a[i]) {
			for (int j = i * i; j < N; j += i) {
				a[j] = true;
			}
		}
	}
	vector<int> pr;

	pr.push_back(2);
	for (int i = 3; i < N; i += 2) {
		if (!a[i])
			pr.push_back(i);
	}

//	printf("%ld",pr.size());

	while (scanf("%d", &n) != EOF && n) {
		if (n == 1) {
			printf("0\n");
		} else {
			phi = n;
			for (vector<int>::iterator it = pr.begin();
					it != pr.end() && *it <= n && n > 1; it++) {
				if (n % *it == 0) {
					phi /= *it;
					phi *= *it - 1;
					while (n % *it == 0) {
						n /= *it;
					}
				}
				//				printf("%d---\n",n);
			}
			if (n > 1) {
				phi /= n;
				phi *= n - 1;
			}
			printf("%d\n", phi);
		}
	}
}

