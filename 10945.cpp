/*
 * 10945.cpp
 *
 *  Created on: May 22, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
using namespace std;

int main() {
	string line;
	char c,d;
	int i,j;
	bool flag;
	while (getline(cin, line) && (line != "DONE")) {
		j=line.length()-1;
		i=0;
		flag=true;
		while (1){
			while (!isalpha(line[i])&&i<=j){
				i++;
			}
			while(!isalpha(line[j])&&i<=j){
				j--;
			}
			if (j<i){
				break;
			}
			if (tolower(line[i])!=tolower(line[j])){
				flag=false;
				break;
			}
			i++;j--;
		}
		if (flag){
			cout<<"You won't be eaten!\n";
		}else{
			cout<<"Uh oh..\n";
		}
	}
}

