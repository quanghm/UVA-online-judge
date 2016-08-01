/*
 * priority.cpp
 *
 *  Created on: May 8, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include <queue>
#include <vector>
#include<string>
using namespace std;

int mailbox[120] = {
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1,  0,  1,  2,  3,  4,  5,  6,  7, -1,
     -1,  8,  9, 10, 11, 12, 13, 14, 15, -1,
     -1, 16, 17, 18, 19, 20, 21, 22, 23, -1,
     -1, 24, 25, 26, 27, 28, 29, 30, 31, -1,
     -1, 32, 33, 34, 35, 36, 37, 38, 39, -1,
     -1, 40, 41, 42, 43, 44, 45, 46, 47, -1,
     -1, 48, 49, 50, 51, 52, 53, 54, 55, -1,
     -1, 56, 57, 58, 59, 60, 61, 62, 63, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
int nbh[8]={ -21, -19,-12, -8, 8, 12, 19, 21 }; /* KNIGHT MOVES*/
class cell{
public:
	int key;
	int val;
	bool visited;
	cell(int k,int v){key=k;val=v;visited=false;}
	cell():key(0),val(65),visited(false){}
};
class lessCell{
public:
	bool operator() (cell & c1,cell & c2){
		return (c1.val<c2.val);
	}
};

int findDist(int s, int t){
	cell x;
	priority_queue<cell,vector<cell>,lessCell> pq;
}

int main(){
	string s,t;
	while (cin>>s>>t){
	}
}



