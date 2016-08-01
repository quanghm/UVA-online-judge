/*
 * 10104.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;

int findxy(int a, int b, int &x, int &y) {
	if (a % b == 0) {
		x = 0;
		y = 1;
		return b;
	}
	if (b % a == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = findxy(b % a, a, y, x);

	int k = b / a;
	x -= y * k;
	return d;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		int x, y;
		int d;
		if (!a) {
			cout <<"0 1 "<< b <<"\n";
		} else if (!b){
			cout <<"1 0 "<< a<<"\n";
		}else {
			d= findxy(a, b, x, y);
			cout << x << ' ' << y << ' ' << d << "\n";
		}

	}
}

