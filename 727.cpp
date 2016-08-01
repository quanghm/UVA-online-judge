/*
 * 727.cpp
 *
 *  Created on: May 24, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string in2pos() {
	string line;
	vector<string> eq;
	int l = 0;
	while (getline(cin, line) && line != "" && line[0] != 41) {	//not equal to bracket
		if (line[0] == 40) {	// open a bracket
			eq.push_back(in2pos());
		} else {
			eq.push_back(line);
		}
		l++;
	}
	// now we have a vector of operands and operators
	int i = 0;
	string result = "", op = "", operand = "";

	result = eq[i++];
	while (i < l && (eq[i][0] == 42 || eq[i][0] == 47)) {
		{
			result = result + eq[i + 1] + eq[i];
			i+=2;
		}
	}
//	cout<<l<<"="<<result<<"!"<<i<<"!!\n";
	while (i < l-1) {

		op = eq[i++];	//opeartors either + or -
		operand = eq[i++];

		while (i < l-1 && (eq[i][0] == 42 || eq[i][0] == 47)) {
			{
				operand = operand + eq[i + 1] + eq[i];
				i+=2;
			}
		}
		result = result + operand + op;
	}
	return result;
}
int main() {
	int n;
	string line;
	cin >> n;
	getline(cin, line);
	getline(cin, line);

	while (n--) {
		if (n) {
			cout << in2pos() << "\n\n";
		} else {
			cout << in2pos() << "\n";
		}
	}
}
