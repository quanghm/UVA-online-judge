/*
 * 10946.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: quang
 */
#include <cstdio>
#include<vector>
#include<queue>
#include<string>

using namespace std;
class compare {
public:
	bool operator()(pair<int, char> i, pair<int, char> j) {
		return (i.first < j.first || (i.first == j.first && i.second > j.second));
	}
};
int main() {
	int x, y, t = 0;
	while (scanf("%d%d", &x, &y) != EOF && x) {
		getchar();

		printf("Problem %d:\n", ++t);
		char a[52][52] = { };
//		bool c[51][51] = { };
		queue<pair<int, int> > h;
		priority_queue<int, vector<pair<int, char> >, compare> w;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				a[i][j] = getchar();
				if (isalpha(a[i][j])) {
					h.push(pair<int, int>(i, j));
				}
			}
			getchar();
		}
		while (!h.empty()) {
			int i = h.front().first;
			int j = h.front().second;
			int s = 0;
			h.pop();
			if (isalpha(a[i][j])) {
				char ch = a[i][j];
				queue<pair<int, int> > v;
				v.push(pair<int, int>(i, j));
				while (!v.empty()) {
					i = v.front().first;
					j = v.front().second;
					v.pop();
					if (a[i][j] == ch) {
						a[i][j] = 46;
						s++;
					}
					if (a[i][j-1]==ch){
						v.push(pair<int,int>(i,j-1));
					}
					if(a[i][j+1]==ch){
						v.push(pair<int,int>(i,j+1));
					}
					if (a[i - 1][j] == ch) {
						v.push(pair<int, int>(i - 1, j));
					}
					if (a[i + 1][j] == ch) {
						v.push(pair<int, int>(i + 1, j));
					}
				}
				w.push(pair<int, char>(s, ch));
			}

		}
		while (!w.empty()) {
			printf("%c %d\n", w.top().second, w.top().first);
			w.pop();
		}
	}
}

