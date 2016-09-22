/*
 * =====================================================================================
 *
 *       Filename:  1056.cpp
 *
 *    Description:  Degree of Saperation
 *
 *        Version:  1.0
 *        Created:  09/21/2016 05:57:37
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
#include <string>
#include <vector>
#include <map>
#include <queue>

#define inf 20000000

using namespace std;

int findMax(int numNodes, 
            vector<vector<int> >&dist,
            vector<vector<int> >&edges){
    int maxDist=0,temp,tempDist;

    // compute min dist for each pair start--end
    for (int start=numNodes; start; start--){
        queue<int> toCheck;
        bool isQueued[51]={};
        toCheck.push(start);
        isQueued[start]=1;


        while (!toCheck.empty()){
            temp=toCheck.front();
            toCheck.pop();
            tempDist = dist[start][temp]+1;
            for (vector<int>::iterator it = edges[temp].begin();
                    it!=edges[temp].end(); it++){
                if (isQueued[*it]) continue;
                toCheck.push(*it);
                isQueued[*it]=1;
                dist[start][*it] = tempDist;
                dist[*it][start] = tempDist;
            }
        }
        
        for (int end=start-1; end; end--){
            if (dist[start][end]==0){ return 0;}
            if (dist[start][end]>maxDist) maxDist=dist[start][end];
        }
    }
    return maxDist;
}
int main(){
    int numNodes, numEdges, edge[2], count, netNum=1;
    string buff;
    while (cin>>numNodes>>numEdges && numNodes){
        vector<vector<int> > dist(51,vector<int>(51,0));
        vector<vector<int> > edges(51);
        map<string,int> nodeNames;
        count=1;

        // read the connection
        for (int i=numEdges; i; i--){
            for (int j=0; j<2; j++){
                cin>>buff;
                if (nodeNames[buff]==0){ // new city
                    nodeNames[buff]=count++;
                }
                edge[j]=nodeNames[buff];
            }
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
            dist[edge[0]][edge[1]]=1;
            dist[edge[1]][edge[0]]=1;
        }

        count = findMax(numNodes, dist, edges);
        cout<<"Network "<<netNum++<<": ";
        (count)?(cout<<count<<"\n\n"):(cout<<"DISCONNECTED\n\n");
    }
}
