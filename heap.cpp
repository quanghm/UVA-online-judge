/*
 * heap.cpp
 *
 *  Created on: May 4, 2015
 *      Author: Quang Hoang
 */
#include<iostream>

using namespace std;

class MaxPQ{
private:
	int keys[500];
	int N=0;
	void swim(int k){
		while (k>1&&less(k/2,k)){
			exch(k/2,k);
			k/=2;
		}
	}
	void sink(int k){
		while (2*k<=N){
			int j=2*k;
			if (j<N&& less(j,j+1)) j++;
			if (!less(k,j)) break;
			exch(k,j);
			k=j;
		}
	}
	void exch(int i,int j){
		int a=keys[i];
		keys[i]=keys[j];
		keys[j]=a;
	}
	bool less(int i,int j){
		return (keys[i]<keys[j]);
	}

public:
	MaxPQ(int ar[]){
		keys=ar;
	}
	int size(){return N;}
	void insert(int k){
		keys[++N]=k;
		swim(N);
	}
	int delMax(){
		int max=keys[1];	// get the max key on top
		exch(1,N--);	// exchange last item
		keys[N+1]=NULL;	// del last item
		sink(1);		// sink
		return max;
	}
};
