/*
 * =====================================================================================
 *
 *       Filename:  10099.cpp
 *
 *    Description:  The Tourist Guide - maximum flow
 *
 *        Version:  1.0
 *        Created:  08/26/2016 15:08:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define INF 2147483647

using namespace std;

vector<int> distFromSource;

class compare{
    public:
        bool operator()(int i, int j){
            return distFromSource[i]<distFromSource[j];
        }
};

bool isCloserToSource(int i, int j){
    return distFromSource[i] < distFromSource[j];
}

int main(){
    int numNodes, numEdges, node1, node2, cap, numRemained, tempNode,tempDist,
        tempEdge, scenario=1;

    while ( (cin>>numNodes>>numEdges) && numNodes){
        vector<vector<pair<int, int> > > edges(numNodes+1);
        vector<bool> isChecked(numNodes+1, 0);
        distFromSource.clear();
        distFromSource.resize(numNodes+1,0);

        // nodes to be checked
        vector<int> toCheck;

        // read the edges
        for (int i = 1; i<= numEdges; i++){
            cin >> node1 >> node2 >> cap;
            edges[node1].push_back(pair<int,int>(node2, cap));
            edges[node2].push_back(pair<int,int>(node1, cap));
        }

        // now node1 is source, node2 is target, cap is the flow
        cin>>node1>>node2>>cap;
        distFromSource[node1] = INF;
        //        cout<<"Searching for route "<<node1<<" to "<<node2<<"\n";

        // let us surf the net
        numRemained = numNodes-1; // number of remaining nodes
        toCheck.push_back(node1); // queue has one member: the source

        for(;;){
            if (toCheck.empty()) break;
            tempNode = toCheck.back();  // largest element
            toCheck.pop_back(); // erase element out of queue

            if (isChecked[tempNode]) continue;

            isChecked[tempNode] = 1; // mark node as checked
            numRemained--; // reduce the number of node remaining
            //            if (!numRemained) break;
            tempDist= distFromSource[tempNode];

            for (vector<pair<int,int> >::iterator it=edges[tempNode].begin();
                    it!=edges[tempNode].end(); ++it){
                if (isChecked[it->first]) continue;
                if (!distFromSource[it->first]) toCheck.push_back(it->first);
                tempEdge = (tempDist < it->second)? tempDist : it->second;
                if (tempEdge > distFromSource[it->first]){
                    distFromSource[it->first]= tempEdge;
                }
            }
            sort(toCheck.begin(),toCheck.end(),isCloserToSource);
        }

        tempDist = distFromSource[node2] - 1;

        if (cap % tempDist){
            tempEdge = cap/tempDist + 1;
        } else {
            tempEdge = cap/tempDist;
        }
        cout<<"Scenario #"<< scenario++<<"\nMinimum Number of Trips = "
            <<tempEdge<<"\n\n";

    }
}
