/*
 * AVLTree.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quang
 */

#include <iostream>

using namespace std;

class AVL {

	class Node {
		int key;
		int val;
		Node* left;
		Node* right;

		int N;

	public:
		Node(int k, int v, int n) :
				key(k), val(v), N(n), left(NULL), right(NULL) {
		}
	};

	Node root;
	int size() {
		return size(&root);
	}
	int get(Node *x, int k) {
		if (x == NULL) {
			return NULL;
		}
		int c = k - x->key;

		if (x < 0) {
			return get(x->left, k);
		} else if (c > 0) {
			return get(x->right, k);
		} else {
			return x->val;
		}
	}
	Node put(Node *x, int k,int v){
		if (x==NULL) return (new Node(k,v,1));
		int c=k-x->key;
		if (c<0)x->left = &put(x->left,k,v);
		else if (c>0) x->right = &put(x->right,k,v);
		else x->val=v;

		x->N=size(x->left)+size(x->right)+1;
		return *x;
	}
public:
	int size(Node *x) {
		if (x == NULL) {
			return 0;
		} else {
			return x->N;
		}
	}
	int get(int k) {
		return get(&root, k);
	}
	void put(int k,int v){
		root=put(&root,k,v);
	}

};
