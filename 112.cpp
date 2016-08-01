/*
 * 112.cpp
 *
 *  Created on: May 18, 2015
 *      Author: quanghoang
 */
/* tree summing */
#include <cstdio>
#include<iostream>
#include<string>
using namespace std;
int start;
string line;
bool treeSum(int s) {
	int n=0, sgn;
	bool r = false;
	if (++start > line.length() - 2) {
		return false;
	}
	if (line[start] == 45) {
		n = 0, sgn = -1;
	} else {
		n = line[start] - 48, sgn = 1;
	}
	while (line[++start] != 40) {
		n = n * 10 + line[start] - 48;
	}
	n*=sgn;
//	printf("start:%d n:%d s:%d\n",start,n,s);

	// line[start] ='('
	if (line[start + 1] != 41) {	//left child is not empty
		r = treeSum(s - n);
		if (r) {
			return true;
		}
		// if sum not found
		start += 2;
//		printf("not found on left, %d\n",start);
		if (line[start+1] != 41) {	//right child is not empty
			r = treeSum(s - n);
			if (r) {
				return true;
			}
			start += 1;
		} else {	// right child is empty
//			printf("right child empty\n");
			start += 1;
		}
	} else {	//left child is empty
		start += 3;
//		printf("%d-\n",start);
		if (line[start] != 41) {	//right child is not empty
			start--;
			r = treeSum(s - n);
			if (r) {
				return true;
			}
			start += 1;
		} else {	//right child is empty
			if (s == n) {
				return true;
			}
//			start += 2;
		}
	}
	return false;
}
int main() {
	int sum;
	int b, t;

	bool flag, neg, left;
	char ch;
	while (scanf("%d", &sum) != EOF) {
		line = "", b = 0, start = 0;
		do {
			do {
				ch = getchar();
			} while (isspace(ch));	//ch is (
			if (ch == 40) {
				b++;
			} else if (ch == 41) {
				b--;
			}
			line += ch;
		} while (b);

//		printf("length: %ld\n", line.length());
//		cout<<sum<<" "<<line<<"\n";
		if (treeSum(sum)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
