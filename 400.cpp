/*
 * 400.cpp
 *
 *  Created on: May 20, 2015
 *      Author: quang
 */
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const string s =
		"------------------------------------------------------------\n";
int main() {
	int count, width, colCount, rowCount, length, j,pos;
	string line;
	vector<string> listFile;
	while (cin >> count) {
		listFile.clear();
		width=0;
		cout<<s;
		getline(cin, line);
		for (int i = 0; i < count; i++) {
			getline(cin, line);
			listFile.push_back(line);
			if (line.length() > width) {
				width = line.length();
			}
		}
		sort(listFile.begin(), listFile.end());
		width += 2;
		colCount = 62 / width;
		rowCount = (count - 1) / colCount + 1;
		for (int i = 0; i < rowCount; i++) {
			for (j=i;j<count;j+=rowCount){
				line = listFile[j];
				cout << line;
				if ( j +rowCount< count) {
					length = line.length();
					for (int k = length; k < width; k++) {
						cout<<" ";
					}
				}else{
					cout<<"\n";
				}

			}
		}

	}
}
