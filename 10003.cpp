/*
 * =====================================================================================
 *
 *       Filename:  10003.cpp
 *
 *    Description:  Cutting Sticks
 *
 *        Version:  1.0
 *        Created:  09/02/2016 07:15:26
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
#include <cstdio>

using namespace std;

#define inf 200000000

int cuts[51]={};
int costs[51][51]={};

int getMinCost(int start, int end){
    if (start+1==end) return 0;

    int min = inf, cost;

    for (int i = start +1; i<end; i++){
        cost = getMinCost(start,i)+ getMinCost(i,end);
        if (cost<min) min = cost;
    }
    return (min + cuts[end]-cuts[start]);
}

int main(){
    int numCuts, c, l, tempMin, tempCost, tempLength, start, end;


    while (cin>>l >> numCuts && l){
        numCuts++;
        cuts[numCuts] = l;
        for (int i = 1 ; i<numCuts; i++){
            cin>> cuts[i];
        }

        for (int diff = 2; diff <= numCuts; diff++){
            start = 0, end = diff;
            while (end <= numCuts){
            tempMin = inf;
                for (int j = start+1; j<end; j++){
                    tempCost = costs[start][j] + costs[j][end];
                    if (tempCost < tempMin) tempMin = tempCost;
                }
                costs[start][end] = tempMin + cuts[end]-cuts[start];
                start++, end++;
            }
        }


        cout<<"The minimum cutting is "<<costs[0][numCuts]<<".\n";
    }
}
