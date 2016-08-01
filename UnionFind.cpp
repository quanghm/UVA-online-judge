/*
 * UnionFind.cpp
 *
 *  Created on: May 18, 2015
 *      Author: qhoang
 */
#include<cstdio>
using namespace std;

class UF {
	int id[];
	int size;
	int total;

public:
	UF(int N) {
		size = N;
		id = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
		total = N;
	}
	int count() {
		return size;
	}

	int find(int p) {
		return id[p];
	}
	bool connected(int p, int q) {
		return (id[p] == id[q]);
	}

	void join(int p,int q) {
		if (connected(p,q)) return;
		int j=id[p];
		for (int i=0;i<total;i++) {
			if(id[i]==j) id[i]=id[q];
		}
	}
};

