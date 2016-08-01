/*
 * 10473.cpp
 *
 *  Created on: May 28, 2015
 *      Author: qhoang
 */
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string line;
//	char h[] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69,
//			70 };
	int t,n;
	while (getline(cin, line) && line[0] != 45) {
		t = line.length();
		if (t > 2 && line	[1] == 120) {	//hex
			istringstream iss(line);
			iss>>hex>>n;
			cout<<dec<<n<<"\n";
		}else{
			istringstream iss(line);
			iss>>n;
			cout<<"0x";
			cout<<hex<<uppercase<<n<<"\n";
		}
	}
}

