/*
 * 494.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: qhoang
 */
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	char ch;
	string line;
	int w;
	while (getline(cin,line)){
		string::iterator it=line.begin();
		w=0;
		while (1){
			while (!isalpha(*it)){
				if (it==line.end()){break;}
				it++;
			}
			if (it==line.end()){cout<<w<<"\n";break;}
			w++;
			while (isalpha(*it)){
				it++;
			}
		}
	}
}
