/*
 * =====================================================================================
 *
 *       Filename:  929.cpp
 *
 *    Description:  Number Maze -- shortest distance
 *
 *        Version:  1.0
 *        Created:  08/22/2016 10:01:16
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
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define inf 2e9

int n,m;
int c,r, dest, current,temp;
int direction[4] = {0,0, 1, -1};

vector<int> minDist;

class isFarther{
    public:
        bool operator()(int i , int j){
            return minDist[i]>minDist[j];
        }
};

void findMinDist(vector<int> & val, vector<bool> &isVisited){
        
    priority_queue<int, vector<int>, isFarther> toCheck;
        
    minDist[m+2] = val[m+2];
    toCheck.push(m+2);
    dest = (n+1)*(m+1)-1;

    for(;;){
        current = toCheck.top();
        toCheck.pop();
            
        if (current == dest){
            cout<<minDist[current]<<"\n";
            return;
        }

        if (isVisited[current]){
            continue;
        }

        temp = minDist[current];
        for (int i = 0; i<4;i++){
            r = current+direction[i];
            if (!isVisited[r]){
                if (minDist[r] > temp + val[r]){
                    minDist[r] = temp + val[r];
                }

                toCheck.push(r);
            }
        }

        isVisited[current] = 1;
    }
}

int main(){
    int t;

    cin >> t;

    while (t--){
        cin >> n >> m;
        direction[0] = m+1;
        direction[1] = -m-1;
        vector<int>( (n+2)*(m+1) +1,inf).swap(minDist);
        vector<int > val((n+2)*(m+1)+1,0);
        vector<bool > isVisited((n+2)*(m+1) + 1, true);

        r=0;
        while (r++<n){
            c=0;
            while (c++<m){
                current = r*(m+1) +c;
                cin>> val[current];
                minDist[current]=inf;
                isVisited[current]=false;
            }
        }

        findMinDist(val,isVisited);

    }
}
