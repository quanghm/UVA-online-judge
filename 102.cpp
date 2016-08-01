/*
 * 102.cpp
 *
 *  Created on: May 28, 2015
 *      Author: quang
 */
/*

 * main.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: quanghoang
 */

#include <iostream>
#include <string>
#include<vector>
using namespace std;

//void line2arr(string line, int &s, int a[3][3]) {
//	istringstream iss(line);
//	int t = 0;
//	s = 0;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			iss >> t;
//			a[i][j] = t;
//			s += t;
//		}
//	}
//}

int main() {
	static char c[3] = { 'B', 'G', 'C' };
	string conf = "BCG", tc = "";
	int a[3][3]; //bottle config
	int s = 0;	// sum
	int m = 0, t = 0;

	string line;

	while (cin >> a[0][0] >> a[0][1] >> a[0][2] >> a[1][0] >> a[1][1] >> a[1][2]
			>> a[2][0] >> a[2][1] >> a[2][2]) {	// read line
		m = 0;
		conf = "GCB";
		s = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				s += a[i][j];
			}
		}
//		line2arr(line, s, a);		// get config
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j) {
					t = a[0][i] + a[1][j] + a[2][3 - i - j];
					if (m <= t) {
						tc = "";
						// inverse permutation
						tc+= c[i];
						tc+= c[j];
						tc+= c[3-i-j];
						//
						if (m == t) {
							//cout << tc << "__"<<m<<"__\n";
							if (conf.compare(tc)>0) {
								conf = tc;
							}
						} else {
							conf=tc;
						}
						m = t;
					}
				}
			}
		}
		cout << conf << " " << (s - m) << endl;
	}

	return 0;
}

