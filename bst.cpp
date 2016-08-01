/*
 * bst.cpp
 *
 *  Created on: May 3, 2015
 *      Author: quanghoang
 */
#include<iostream>
using namespace std;
class bst { //balance binary search tree
	int key;
	int val;
	int size;
	bst* dad;
	bst* left;
	bst*right;
public:
	void delMin();
	int getMin();
	int getMax(){
		bst* r=this;
		while (r->right!=NULL){
			r=r->right;
		}
		return r->key;
	}
	bool insert(int k);

	bst(int k, int v);
};

bst::bst(int k, int v) :
		key(k), val(v), size(1), left(NULL), right(NULL),dad(NULL) {
}

bool bst::insert(int k){

	return false;
}
