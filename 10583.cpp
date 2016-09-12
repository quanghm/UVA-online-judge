/*
 * =====================================================================================
 *
 *       Filename:  10583.cpp
 *
 *    Description:  Ubiquitous Religions -- Union Find
 *
 *        Version:  1.0
 *        Created:  09/11/2016 04:25:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>

using namespace std;
int id[50001]={};

class UF{
private:
    int size;
    int numComp;

public:
    UF(int n){
        size = n;
        numComp=n;
        for (int i = 1;i<=n; i++){
            id[i]=i;
        }
    }

    // find the root of i
    int root(int i){
        while (i!=id[i]){
            id[i] = id[id[i]];
            i=id[i];
        }
        return i;
    }

    // union
    void unite(int p, int q){
        int i = root(p);
        int j = root(q);
        if (i!=j){
            id[i]=j;
            numComp--;
        }
    }

    // get numComp
    int getNumComponents(){
        return numComp;
    }
};

int main(){
    int n, m,p,q,c=1;
    while (cin>>n>>m && n){
        UF uf(n);
        while (m--){
            cin>>p>>q;
            uf.unite(p,q);
        }
        cout<<"Case "<<c++<<": "<<uf.getNumComponents()<<"\n";
    }
}
