/*
 * 10082.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: quang
 */
#include<cstdio>
//#include<map>
using namespace std;

int main() {
//	map<char, char> D;
	int D[256]={};
	D['1'] = '`', D['2'] = '1', D['3'] = '2', D['4'] = '3', D['5'] = '4';
	D['6'] = '5', D['7'] = '6', D['8'] = '7', D['9'] = '8', D['0'] = '9';
	D['-'] = '0', D['='] = '-';

	D['W'] = 'Q', D['E'] = 'W', D['R'] = 'E', D['T'] = 'R', D['Y'] = 'T';
	D['U'] = 'Y', D['I'] = 'U', D['O'] = 'I', D['P'] = 'O', D['['] = 'P';
	D[']'] = '[', D[92] = ']';

	D['S'] = 'A', D['D'] = 'S', D['F'] = 'D', D['G'] = 'F', D['H'] = 'G';
	D['J'] = 'H', D['K'] = 'J', D['L'] = 'K', D[';'] = 'L', D[39] = ';';

	D['X'] = 'Z', D['C'] = 'X', D['V'] = 'C', D['B'] = 'V', D['N'] = 'B';
	D['M'] = 'N', D[','] = 'M', D['.'] = ',', D[47] = '.';

	D[10] = 10;
	D[32] = 32;
	char ch;
	while ((ch = getchar()) != EOF) {
		putchar(D[ch]);
	}
}
