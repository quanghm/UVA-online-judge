/*
 * 11503.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	int c, n;
	string a, b, t;
	cin >> c;
	while (c--) {
		cin >> n;
		map<string, int> nw;
		map<string, string> pr;
		while (n--) {
			cin >> a >> b;
			if (nw[a] == 0) {
				pr[a] = a;
				nw[a] = 1;
			}
			if (nw[b] == 0) {
				pr[b] = b;
				nw[b] = 1;
			}
			if (pr[a] != pr[b]) {
				if (nw[pr[a]] > nw[pr[b]]) {
					t = pr[b];
					for (map<string, string>::iterator it = pr.begin();
							it != pr.end(); it++) {
						cout<<it->first<<":"<<it->second<<" ";
						if (it->second == t) {
							it->second = pr[a];
						}
					}
					nw[a] += nw[b];
					nw[b] = nw[a];
					nw[pr[a]]=nw[a];
					cout<<"\n";
				} else {
					t = pr[a];
					cout<<t<<"\n";
					for (map<string, string>::iterator it = pr.begin();
							it != pr.end(); it++) {
						cout<<it->first<<":"<<it->second<<" ";
						if (it->second == t) {
							it->second = pr[b];
						}
					}
					nw[b]+=nw[a];
					nw[a] = nw[b];
					nw[pr[b]]=nw[b];
					cout<<"\n";
				}
			}
			printf("%d\n", nw[a]);
		}
	}
}

