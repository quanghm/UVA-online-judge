/*
 * 10370.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
using namespace std;

int main() {
	int n, t, temp;
	double s;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		s=0;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			pq.push(temp);
			s += temp;
		}
		s /= n;
		temp = 0;
		while (!pq.empty() && pq.top() > s) {
			temp += 1;
			pq.pop();
		}
		s=temp*100.00/(n*1.0);
		printf("%.3lf%c\n",s,37);
	}
}

