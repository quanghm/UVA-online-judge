/*
 * 492.cpp
 *
 *  Created on: May 31, 2015
 *      Author: quanghoang
 */
#include<string>
#include<cstdio>
#include<queue>
using namespace std;

int main() {
	int c;
	char ch;
	const string vowels = "aeoiuAEOIU";
	while (1) {
		ch = getchar();
		bool b = (vowels.find(ch) == -1);
		if (isalpha(ch)) {
			queue<char> word;
			word.push(ch);

			while ((ch = getchar()) != EOF && isalpha(ch)) {
				word.push(ch);
			}
			if (b) {
				word.push(word.front());
				word.pop();
			}
			while (!word.empty()) {
				putchar(word.front());
				word.pop();
			}
			printf("ay");
		}
		if (ch != EOF) {
			putchar(ch);
		} else {
			return 0;
		}
	}
}

