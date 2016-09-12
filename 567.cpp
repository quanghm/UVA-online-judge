/*
 * =====================================================================================
 *
 *       Filename:  567.cpp
 *
 *    Description:  Risk -- shortest distance
 *
 *        Version:  1.0
 *        Created:  09/09/2016 09:16:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getShortestDist(int start, int end, 
                    vector<vector<int> >&shortest,
                    vector<vector<bool> > &edges){
    if (shortest[start][end]<21 ) return shortest[start][end];
    
    bool isVisited[21]={};
    queue<int> toVisit;
    int tempEnd,minDist;

    toVisit.push(start);
    isVisited[start]=1;
    shortest[start][start] = 0;

    while (!toVisit.empty()){
        tempEnd = toVisit.front();
        toVisit.pop();
        minDist = shortest[start][tempEnd];
        if (tempEnd == end) return minDist;
        minDist++;

        for (int i = 1; i<21; i++){
            if (edges[tempEnd][i]){
                if (shortest[start][i]> minDist){
                    shortest[start][i] = minDist;
                    shortest[i][start] = minDist;
                }
                if (!isVisited[i]){
                    isVisited[i]=1;
                    toVisit.push(i);
                }
            }
        }
    }
    return shortest[start][end];
}

int main(){
    int start,end, numQueries,test=0;

    for (;;){
        vector<vector<bool> > edges(21,vector<bool>(21,0) );
        vector<vector<int> > shortest(21,vector<int>(21,21) );
        for (int i=1;i<20;i++){
            if (scanf("%d",&start)==EOF) return 0; // number of edges
            while (start--){
                scanf("%d",&end);
                edges[i][end] = 1, edges[end][i]=1;
            }
        }
        scanf("%d",&numQueries);

        printf("Test Set #%d\n",++test);
        while (numQueries--){
            scanf("%d%d",&start,&end);
            printf("%2d to%3d: %d\n",start,end,
                    getShortestDist(start,end,shortest,edges) );
        }
        printf("\n");
    }
}
