/*
 * =====================================================================================
 *
 *       Filename:  103.cpp
 *
 *    Description:  Stacking Boxes
 *
 *        Version:  1.0
 *        Created:  08/15/2016 16:16:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > boxes(30, vector<int>(10,0));
int numBoxes, dim;

bool isIn(int i, int j){
    for (int l =0;l<dim; ++l){
        if (boxes[i][l]>= boxes[j][l]){
            return false;
        }
    }
    return true;
}

void visit(int i, 
        vector<vector<bool> >&edges, 
        vector<bool> &isVisited, 
        vector<int> &ordered){
    if (isVisited[i]) return;

    for (int j=0; j<numBoxes; ++j){
        if (edges[i][j]) visit(j, edges, isVisited, ordered);
    }
    
    isVisited[i]=1;
    ordered.push_back(i);
}
int main(){
    
    while (cin>>numBoxes>>dim){
        vector<vector<bool> > edges(numBoxes,vector<bool>(numBoxes));
        vector<bool> isVisited(numBoxes,0);
        vector<int> ordered;

        for (int i = 0; i<numBoxes; i++){
            for (int j = 0; j<dim; j++){
                cin>>boxes[i][j];
            }
            sort(boxes[i].begin(),boxes[i].begin()+dim);
        }
        
        for (int i=0; i< numBoxes; i++){
            for (int j=0;j<numBoxes; ++j){
                if (isIn(i,j)){
                    edges[i][j]=true;
                }
            }
        }
        
        vector<int> dist(numBoxes, 1);
        vector<int> pre(numBoxes);

        int max = 1, start;

        for (int i = 0; i<numBoxes;++i){
            visit(i, edges, isVisited, ordered);
        }

//        for (int i =0; i<numBoxes;++i){
//            cout<<ordered[i]<<"--";
//        }
//        cout<<"\n";

        for (int j=0; j<numBoxes; ++j){
            for (int i=j+1;i<numBoxes; ++i){
                if (edges[ordered[i]][ordered[j]] ) {
                    if (dist[ordered[i]] <= dist[ordered[j]]){
                        dist[ordered[i]] = dist[ordered[j]]+1;
                        pre[i] = j;
                    }

                    if (dist[ordered[i]]>max){
                        max = dist[ordered[i]]; 
                        start = i;
                    }
                }
            }
        }

        cout<<max<<'\n';
        while(max--){
            cout << ordered[start]+1;
            start= pre[start];
            if (max){
                cout<<" ";
            } else{
                cout<<"\n";
            }
        }
    }
}
