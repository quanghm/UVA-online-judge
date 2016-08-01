/*
 * 10062.cpp
 *
 *  Created on: May 22, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
bool doCompare(pair<int,char>i,pair<int,char>j){
	if (i.first<j.first){return true;}
	else if (i.first==j.first){
		return j.second<i.second;
	}else{return false;}
}
int main(){
	string line;
	bool first=true;
	while (getline(cin,line)){
		if (first){
			first=false;
		}else{
			cout<<"\n";
		}
		vector<pair<int,char> > out;
		map<char,int> val;

		for (string::iterator it=line.begin();it!=line.end();it++){
			val[*it]++;
		}
		for (map<char,int>::iterator it=val.begin();it!=val.end();it++){
			out.push_back(pair<int,char>(it->second,it->first));
		}
		sort(out.begin(),out.end(),doCompare);
//		for (vector<pair<int,char> >::reverse_iterator it=out.rbegin();it!=out.rend();it++){
		for (vector<pair<int,char> >::iterator it=out.begin();it!=out.end();it++){
		cout<<(int)(it->second)<<" "<<it->first<<"\n";
		}
	}
}

