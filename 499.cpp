/*
 * 499.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class Compare {
public:
	bool operator() (pair<char,int> i, pair<char,int> j) {
		return (i.second<j.second ||(i.second==j.second &&i.first>j.first));
	}
};
bool isLess(pair<char,int> i, pair<char,int> j) {
	return (i.second<j.second ||(i.second==j.second &&i.first>j.first));
}
int main() {
	string line;
	while (getline(cin,line)){
		map<char ,int>f;
		for (string::iterator it=line.begin();it!=line.end();it++){
			if (isalpha(*it)){
				f[*it]++;
			}
		}
//		sort(f.begin(),f.end(),isLess);
//		int max=f.begin()->second;
//		for (map<char,int>::iterator it=f.begin();it!=f.end();it++){
//			if (max==it->second){
//				cout<<it->first;
//			}
//		}



		priority_queue<int, vector<pair<char,int> >,Compare> pq;
		for (map<char,int>::iterator it=f.begin();it!=f.end();it++){
			pq.push(*it);
		}
		int max=pq.top().second;
		while (!pq.empty()&&max==pq.top().second){
			cout<<pq.top().first;
			pq.pop();
		}

		cout<<" "<<max<<"\n";
	}
}
