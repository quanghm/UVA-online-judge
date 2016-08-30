/*
 * =====================================================================================
 *
 *       Filename:  10000.cpp
 *
 *    Description:  Longest Path -- DAG
 *
 *        Version:  1.0
 *        Created:  08/27/2016 14:56:18
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
#include <vector>
#include <algorithm>
#include <utility>

#define inf 1e6

using namespace std;

void visit(int i, 
        vector<bool> &isChecked, 
        vector<int> &ordered,
        vector<vector<int> > &children){
    if (isChecked[i]) return;
    isChecked[i] = 1;

    for (vector<int>::iterator it = children[i].begin();
            it!=children[i].end();it++){
        visit(*it,isChecked,ordered, children);
    }

    ordered.push_back(i);
}

int main(){
    int numNodes, source, n1, n2, t=0, tempDist,maxDist;

    while ( (cin>>numNodes)&& numNodes){
        cin>>source;

        // reset distFromSource
        vector<int> distFromSource(numNodes+1,0);
        vector<bool> isChecked(numNodes+1,0);
        vector<int> ordered;

        vector<vector<int> > children(numNodes+1);

        // read the line
        while ( (cin>>n1>>n2) && n1){
            children[n1].push_back(n2);
        }

        // surfing through the nodes
        for (int i = 1;i<=numNodes;i++){
            visit(i,isChecked,ordered,children);
        }

        distFromSource[source] = 1;
        maxDist = 1;
        n2 = numNodes+1;

        for (vector<int>::reverse_iterator rit = ordered.rbegin();
                rit !=ordered.rend(); rit++){
            // cannot go from source to this
//            cout << "checking "<<*rit<<"\n";
            if (!distFromSource[*rit]) continue;

            tempDist = distFromSource[*rit];
            if (tempDist > maxDist || (tempDist == maxDist && *rit<n2)){
                maxDist = tempDist, n2 = *rit;
            } 
//            cout<<"|___distance "<<tempDist<<"\n";
            tempDist++;

            for (vector<int>::iterator it = children[*rit].begin();
                    it !=children[*rit].end(); it++){
                if (distFromSource[*it] < tempDist){
                    distFromSource[*it]= tempDist;
                }
//                cout <<*it<< " ";
            }
//            cout<<"\n";
        }
        cout<<"Case "<<++t<<": The longest path from "<< source<< 
            " has length "<<maxDist-1<<", finishing at "<<n2<<".\n\n";
    }
}
