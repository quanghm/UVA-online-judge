/*
 * uva254-TowersOfHanoi.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: Quang Hoang
 */
#include <iostream>
#include <stack>
using namespace std;

stack<int> pegs[3];

int n = 8;
int m = 45;
int i;

int ar[3] = { };
void toBinary(){
	stack<bool> b;
	int l=i;
	int j=0;
	while (l){
		j++;
		b.push(l%2);
		l/=2;
	}
	while (j++<n){
		b.push(0);
	}
	while (!b.empty()){
		cout << b.top();
		b.pop();
	}
}

void move(int k, int j) {
	int d = pegs[k].top();
	pegs[k].pop();
	pegs[j].push(d);

	ar[k]--;
	ar[j]++;

	toBinary();
	cout << ": " << k << j <<3 -k - j << endl;
}

int main() {

	while (scanf("%d%d", &n, &m)) {
		if (n == 0) {
			return 0;
		}
		ar[0] = n;
		ar[1] = 0;
		ar[2] = 0;
		pegs[0].empty();
		pegs[1].empty();
		pegs[2].empty();
		pegs[1].push(n);
		pegs[2].push(n);
		while (n--) {
			pegs[0].push(n);
		}

		i = 0;
		int one = 0, next = 1, other = 2;
		while (i++ < m) {
			//	odd move, one to next
			next = (one + 1) % 3;
			other = (one + 2) % 3;
			move(one, next);
			if (i++ >= m) {
				break;
			}

			//even move, other legal move
			if (pegs[one].top() < pegs[other].top()) {
				move(one, other);
			} else {
				move(other, one);
			}
			one = next;
		}
		cout << ar[0] << " " << ar[1] << " " << ar[2] << endl;
	}
	return 0;
}
