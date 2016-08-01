/*
 * uva439.cpp
 *
 *  Created on: May 7, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int ma = 99;
//class check{
//public:
//	bool operator()(pair<int,int>i,pair<int,int>j){
//		return (i.first>j.first);
//	}
//};
int main() {
	string cs, ct;
	int s, t, c;
	int nbh[8] = { -21, -19, -12, -8, 8, 12, 19, 21 };
	while (cin >> cs >> ct) {
		int a[120] = { //
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //
						-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, ma, ma, ma, ma, ma, ma, ma, ma, -1, //
						-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //
						-1, -1, -1, -1, -1, -1, -1, -1, -1, -1 //
				};
		s = (cs[0] - 95)*10 + (cs[1] - 48);
		t = (ct[0] - 95)*10 + (ct[1] - 48);

//		priority_queue<int,pair<int,int>,check> q;
		queue<int> q;
		a[s] = 0;
		q.push(s);
		while (!q.empty()) {
			s = q.front();
			q.pop();
			if (s == t) {
				break;
			}
			for (int i = 0; i < 8; i++) {
				c = s + nbh[i];	// search through neighborhood
				if (a[c] == ma) { //not checked
					q.push(c);
				}
				if (a[c] > a[s]) {
					a[c] = a[s] + 1;
				}
			}
		}
		cout << "To get from " << cs<< " to " << ct <<" takes "<< a[s]
				<< " knight moves.\n";
	}
}

