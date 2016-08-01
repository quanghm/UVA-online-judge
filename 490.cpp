/*
 * 490.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: qhoang
 */
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	string line;
	char c[100][100] = { };
	memset(c, 32, 10000);
	int n = 0, l, m = 0;

	while (getline(cin, line)) {
		l=line.length();
		if (m < l) {
			m = l;
		}
		for (int i=0;i<l;i++){
			c[n][i]=line[i];
		}
		n++;
	}
	n--;
	for (int j=0;j<m;j++){
		for (int i=n;i>=0;i--){
			cout<<c[i][j];
		}
		cout<<"\n";
	}
}

