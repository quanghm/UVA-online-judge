/*
 * 763.cpp
 *
 *  Created on: May 14, 2015
 *      Author: quanghoang
 */

#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;

string s[2];
void add(int i,int j){	// add at position i
	int l=s[j].length()-1;
	if (i<0){
		s[j]='1'+s[j];
		return;
	}
	if (s[j][i]==48){	// 0
		if (s[j][i-1]==49){ //*10+1
			s[j][i-1]=48;
			add(i-2,j);
			return;
		}else{	// 00+1
			if (i<l&&s[j][i+1]==49){//001+10
				s[j][i]=48;s[j][i+1]=48;
				add(i-1,j);
				return;
			}else{//000+10 or 00+1
				s[j][i]=49;
			}
		}
	}else{	// 010+010
		if (i==l){	// last digit: *01+1
			s[j][l]=48;
			add(l-1,j);
			return;
		}else{	// 010+10
//			s[j][i]=48;
			add(i+1,j);
			add(i+2,j);
		}
	}
}
int main(){
	int len;
	while(cin>>s[0]>>s[1]){
		if (s[0].length()>s[1].length()){
			len=s[0].length();
			for (int i=0;i<len;i++){
				add(i,0);
			}
			cout<<s[0]<<"\n";
		}else{
			len=s[1].length();
			for (int i=0;i<len;i++){
				add(i,1);
			}
			cout<<s[1]<<"\n";
		}
	}
}








//const int N = 6;
//const int base = 100000;
//const int log10 = 5;	// log_10(base);
//class BigInt {
//public:
//	int val[N];
//	BigInt() :
//			val() {
//	}
//
//	BigInt(int i) :
//			val() {
//		val[0] = i;
//	}
//
//	void add(BigInt t) {
//		int c = 0;
//
//		for (int j = 0; j < N; j++) {
//			c += val[j] + t.val[j];
//			val[j] = c % base;
//			c /= base;
//		}
//	}
//	void substract(BigInt t) {
//		int c = 0;
//
//		for (int j = 0; j < N; j++) {
//			c += t.val[j];
//			if (c <= val[j]) {
//				val[j] -= c;
//				c = 0;
//			} else {
//				val[j] += base - c;
//				c = 1;
//			}
//		}
//	}
//
////	void print() {
////		int j = N - 1;
////		while (!val[j]) {
////			j--;
////		}
////		//j : left most non-zero digit
////		if (j < 0) {
////			cout << "0\n";
////			return;
////		}
////		printf("%d", val[j--]);
////		for (int i = j; i > -1; i--) {
////			printf("%0*d", log10, val[i]);
////		}
////		cout << "\n";
////	}
//};
//bool larger(BigInt i1, BigInt i2) {
//	//bool r=true;
//	int n = N - 1;
//	while (i1.val[n] == i2.val[n]) {
//		n--;
//	}
//	return ((n >= 0) && (i1.val[n] > i2.val[n]));
//}
//
//int main() {
//	BigInt fibs[103];
//	fibs[0] = BigInt(1);
//	fibs[1] = BigInt(2);
//	for (int i = 2; i < 103; i++) {
//		fibs[i].add(fibs[i - 1]);
//		fibs[i].add(fibs[i - 2]);
//	}
//
//	string s;
//	int l;
//	bool first = true;
//	while (cin >> s) {
//		if (first) {
//			first = false;
//		} else {
//			cout << "\n";
//		}
//		BigInt u;
//
//		//first Fibinary number
//		l = s.length() - 1;
//		for (int i = 0; i <= l; i++) {
//			if (s[i] == 49) {
//				u.add(fibs[l - i]);
//			}
//		}
//
//		// add second fibinary number
//		cin >> s;
//		l = s.length() - 1;
//		for (int i = 0; i <= l; i++) {
//			if (s[i] == 49) {
//				u.add(fibs[l - i]);
//			}
//		}
//		l = 103;
//		while (l--) {
//			if (!larger(fibs[l], u)) {
//				break;
//			}
//		}
//		if (l < 0) {
//			cout << "0\n";
//		} else {
//			do {
//				if (larger(fibs[l], u)) {
//					cout << "0";
//				} else {
//					u.substract(fibs[l]);
//					cout << "1";
//				}
//				l--;
//			} while (l >= 0);
//			cout << "\n";
//		}
//
//	}
//
//}
//
