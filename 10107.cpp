/*
 * 10107.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quanghoang
 */

#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main(){
	priority_queue<int> minQueue;
	priority_queue<int,vector<int>,greater<int> > maxQueue;

	int n,aux,med,c=0;
	minQueue.push(0);
	maxQueue.push(2147483647);
	while(cin>>n){
		c++;
		minQueue.push(n);
		if (c%2){
			if(minQueue.top()>maxQueue.top()){
				aux=minQueue.top();
				minQueue.pop();
				minQueue.push(maxQueue.top());
				maxQueue.pop();
				maxQueue.push(aux);
			}
			cout<< minQueue.top()<<"\n";
		}else{
			aux=minQueue.top();
			minQueue.pop();
			maxQueue.push(aux);
			aux=(minQueue.top()+maxQueue.top())/2;
			cout<<aux<<"\n";
		}
	}
}


