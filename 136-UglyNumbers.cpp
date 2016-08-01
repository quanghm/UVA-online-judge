/*
 * uva136-UglyNumbers.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: Quang Hoang
 */

#include <iostream>
#include<algorithm>
#include<queue>
#include <vector>

using namespace std;

int main() {
	long long n,m,l=1;
	priority_queue<int,vector<long>,greater<long> > ugly;
	ugly.push(1);n=0;
	while (n<1500){
		ugly.push(l*2);
		ugly.push(l*3);
		ugly.push(l*5);
		l=ugly.top();
		n++;
		while (ugly.top()==l){
			ugly.pop();
		}
	}

	cout << "The 1500'th ugly number is " << l << "." << endl;
}

