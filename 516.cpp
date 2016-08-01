/*
 * 516.cpp
 *
 *  Created on: May 20, 2015
 *      Author: quang
 */
#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

const int M=182;
int main(){

	int m,n,s,d;
	string line;
	m=15;
	bool a[M]={};
	vector<int> primes;

	for (int i=2;i<m;i++){
		if (!a[i]){
			for (int j=i*i;j<M;j+=i){
				a[j]=1;
			}
		}
	}
	for (int i=2;i<M;i++){
		if (!a[i]){
			primes.push_back(i);
		}
	}
	while (getline(cin,line)&&line!="0"){
		istringstream iss(line);
		s=1;
		//read input line
		while (iss>>m>>n){
			while(n--){
				s*=m;
			}
		}

		//factorize s-1;
		s-=1;
		stack<int> toPrint;
		for (int i=0;i<primes.size();i++){
			d=primes[i];
			if (d>s){break;}
			if (s%d==0){
				n=0;
				while (s%d==0){
					s/=d;
					n++;
				}
				toPrint.push(n);
				toPrint.push(d);
			}
		}
		if (s>1){
			toPrint.push(1);
			toPrint.push(s);
		}
		while (1){
			cout<<toPrint.top();
			toPrint.pop();
			if (toPrint.empty()){
				cout<<"\n";
				break;
			}else{
				cout<<" ";
			}
		}
	}
}
