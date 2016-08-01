/*
 * uva10098.cpp
 *
 *  Created on: May 12, 2015
 *      Author: qhoang
 */
#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main(){
	int n;
	cin>>n;
	string line;
	getline(cin,line);

	while (n--){
		getline(cin,line);
		sort(line.begin(),line.end());
		do {
			cout<<line<<"\n";
		} while (next_permutation(line.begin(),line.end()));
		cout<<"\n";
		//if(n)cout<<"\n";
	}
}



