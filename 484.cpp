/*
 * uva484.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	long long s;
	vector<long long> orders;
	map<long long,long > values;

	while (cin>>s){
		if (!values[s]){
			orders.push_back(s);
		}
		values[s]++;
	}
	for (vector<long long>::iterator it=orders.begin();it!=orders.end();it++){
		cout<<*it<<" "<<values[*it]<<"\n";
	}
}
