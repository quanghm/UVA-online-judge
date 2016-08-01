/*
 * 11476.cpp
 *
 *  Created on: May 20, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;

const int N=10000;
int main(){
	int m=100;
	bool a[N]={};
	vector<int> primes;

	for (int i=2;i<N;i++){
		if (!a[i]){
			for (int j=i*i;j<N;j+=i){
				a[j]=1;
			}
		}
	}
	primes.push_back(2);
	for (int i=3;i<N;i+=2){
		if (!a[i]){
			primes.push_back(i);
		}
	}
	// check if a number is prime;
	for (int i=N+1;i<100000000;i+=2){

	}
}
