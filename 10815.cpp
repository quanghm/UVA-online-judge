/*
 * 10815.cpp
 *
 *  Created on: May 22, 2015
 *      Author: qhoang
 */
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	char c;
	string word;
	string line;
	map<string, bool> dict;
	vector<string> order;
	bool flag;

	while (getline(cin, line)) {
//		flag = false;
		string::iterator it = line.begin();
		while (it != line.end()) {
			word = "";
			while (it != line.end()) {
				c = *it;
				it++;
				if (isalpha(c)) {
					word += tolower(c);
				} else {
					break;
				}
			}
//		transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (!dict[word]&&word!="") {
				dict[word] = true;
				order.push_back(word);
			}
		}
	}
	sort(order.begin(),order.end());
	for (vector<string>::iterator it=order.begin();it!=order.end();it++){
		cout<<*it<<"\n";
	}
//	while (!order.empty()) {
//		cout << order.top() << "\n";
//		order.pop();
//	}

}

