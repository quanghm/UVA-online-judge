/*
 * =====================================================================================
 *
 *       Filename:  10459.cpp
 *
 *    Description:  The Tree Root
 *
 *        Version:  1.0
 *        Created:  08/24/2016 11:53:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int numNodes, nodeDegree, node, length, depth; // max depth

    while (cin >> numNodes){
        vector<vector<int> > edges(numNodes+1);
        vector<int> degree(numNodes+1);
        vector<bool> isVisited(numNodes+1);
        vector<int> toRemove, buff;

        depth = 0; // best maxDepth

        for (int i = 1; i <= numNodes; ++i){
            cin>> nodeDegree;
            degree[i] = nodeDegree;
            isVisited[i]=0;

            for (int j = 0; j<nodeDegree; ++j){
                cin>> node;
                edges[i].push_back(node);
            }
            if (nodeDegree == 1){
                toRemove.push_back(i);
            }
        }

        for (int numRemain = numNodes; numRemain > 2; ){
            depth++;
            numRemain -= toRemove.size();
            for (vector<int>::iterator iit = toRemove.begin();
                    iit!=toRemove.end();iit++){
                node = *iit;
                degree[node]--;

                for (vector<int>::iterator it = edges[node].begin();
                        it != edges[node].end(); ++it){
                    if (degree[*it]){
                        degree[*it] --;
                    }

                    if (degree[*it]==1){
                        buff.push_back(*it);
                    }
                }
            }
            toRemove.swap(buff);
            buff.clear();
        }

        // get the right order (actually either 1 or 2 elements)
        sort(toRemove.begin(),toRemove.end());
        
        queue<int> toMeasureDepth;

        cout<<"Best Roots  :";
        for (vector<int>::iterator iit=toRemove.begin();
                iit!=toRemove.end();++iit){
            cout<<" "<<*iit;
        }
        cout<<"\n";
        
        // buff now contains worst nodes
        // degree now contains distance of a node to bestNodes
        degree[toRemove[0]] = depth;
        toMeasureDepth.push(toRemove[0]);

        if (toRemove.size()==2){
            isVisited[toRemove[1]]=1;
            for (vector<int>::iterator it = edges[toRemove[1]].begin();
                    it != edges[toRemove[1]].end(); ++it){
                if (*it != toRemove[0]){
                    degree[*it]= depth-1;
                    toMeasureDepth.push(*it);
                }
            }
        }

        while (!toMeasureDepth.empty()){
            node = toMeasureDepth.front();
            isVisited[node]=1;
            length = degree[node]-1;
            toMeasureDepth.pop();

            if (degree[node]){
                for (vector<int>::iterator it = edges[node].begin();
                        it != edges[node].end(); ++it){
                    if (isVisited[*it]) continue;
                    degree[*it] = length;
                    toMeasureDepth.push(*it);
                }
            } else {
                buff.push_back(node);
            }
        }
        sort(buff.begin(),buff.end());

        cout<<"Worst Roots :";
        for (vector<int>::iterator it = buff.begin();
                it != buff.end(); ++it){
            cout<<" "<<*it;
        }
        cout<<"\n";
    }
}

