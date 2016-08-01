/*
 * 10033.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;

int main() {
	int c, x, d, n, u, temp;
	string line;
	cin >> c;
	getline(cin, line);
	getline(cin, line);

	while (c--) {
		int reg[10] = { };
		int ram[1000] = { };
		bool nh = true;
		int count = 0;
		u = 0;
		while (getline(cin, line) && line != "") {
			for (int i = 0; i < 3; i++) {
				ram[u] = ram[u] * 10 + line[i] - 48;
			}
			u++;
		}
		u = 0;
		while (nh) {
			count++;
//			cout << "ram[u="<<u<<"]="<<ram[u]<<"\n";
			n = ram[u] % 10, x = ram[u] / 10, d = x % 10, x /= 10;

			switch (x) {
			case 0:	//0
//				cout << "reg[" << n << "]=" << reg[n] << ",ram[reg[n="<<n<<"]]="
//
//						<< ram[reg[n]] << "\n";
//				cout<<"reg[d="<<d<<"]="<<reg[d]<<"\n";
//				temp = reg[n] / 10;
				if (reg[n]) {
					u = reg[d];
				} else {
					u++;
				}
//				cout<<"New u="<<u<<"\n";
				break;
			case 1:	//1
				nh = false;
				break;
			case 2:	//2
				reg[d] = n;
				break;
			case 3:	//3
				reg[d] = (reg[d] + n) % 1000;
				break;
			case 4:	//4
				reg[d] = (reg[d] * n) % 1000;
				break;
			case 5:	//5
				reg[d] = reg[n];
				break;
			case 6:	//6
				reg[d] = (reg[d] + reg[n]) % 1000;
				break;
			case 7:	//7
				reg[d] = (reg[d] * reg[n]) % 1000;
				break;
			case 8:	//8
				reg[d] = ram[reg[n]];
				break;
			case 9:	//9
				ram[reg[n]] = reg[d];
				break;
			}
			if (x) {
				u++;
			}
		}
		if (c) {
			cout << count << "\n\n";
		} else {
			cout << count << "\n";
		}
	}
}

