/*
 * uva11727.cpp
 *
 *  Created on: May 5, 2015
 *      Author: quanghoang
 */

#include<iostream>
using namespace std;

int main() {
	int m, e = 0, d;
	int a, b, c;

	cin >> m;
	while (e++ < m) {
		cin >> a >> b >> c;
		if (a < b) {
			if (b < c) {	//a<b<c
				d = b;
			} else if (a < c) {
				d = c;
			} else {
				d = a;
			}
		} else {	//a>=b
			if (b < c) {	//b<a,b<c
				if (a < c) {
					d = a;
				} else {	//b<a,b<c, c<=a
					d = c;
				}
			} else { //c<b<a
				d = b;
			}
		}
		cout<<"Case "<<e<<": "<<d<<endl;
	}
}

