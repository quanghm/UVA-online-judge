/*
 * =====================================================================================
 *
 *       Filename:  544.cpp
 *
 *    Description:  Heavy Cargo
 *
 *        Version:  1.0
 *        Created:  09/20/2016 09:15:57
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
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

#define INF 2147483647

vector<int> distFromSource;

bool isCloserToSource(int i, int j){
    return distFromSource[i] < distFromSource[j];
}

int main(){
    int scene=1, numNodes, numEdges, start, end, count,load;
    string buff;

    while (cin>>numNodes>>numEdges && numNodes){
        map<string, int> cities;
        vector<vector<pair<int,int> > > edges(numNodes+1);
        vector<bool> isChecked(numNodes+1,0);
        vector<int> toCheck;
        distFromSource.clear();
        distFromSource.resize(numNodes+1,0);

        count=1;

        // read edges information
        for (int i=numEdges; i; i--){
            // start
            cin >> buff; 
            if (cities[buff]==0){
                cities[buff]=count++;
            }
            start = cities[buff];
            // end
            cin >> buff;
            if (cities[buff]==0){
                cities[buff]=count++;
            }
            end = cities[buff];

            cin >> load;

            edges[start].push_back(pair<int,int>(end,load));
            edges[end].push_back(pair<int,int>(start,load));       
        }
        cin>> buff; start=cities[buff];
        cin>> buff; end=cities[buff];

        distFromSource[start] = INF;
        int numRemained = numNodes-1;
        toCheck.push_back(start);

        while (!toCheck.empty()){
            start = toCheck.back(); // largest element
            toCheck.pop_back(); // erase element out of queue

            if (isChecked[start]) continue;

            isChecked[start]=1; // mark node as checked
            numRemained--; // 
            load = distFromSource[start];

            for (vector<pair<int,int> >::iterator it=edges[start].begin();
                   it!=edges[start].end(); it++){
                if (isChecked[it->first]) continue;
                if (!distFromSource[it->first]) toCheck.push_back(it->first);

                count = (load < it->second)? load : (it->second);

                if (count>distFromSource[it->first]){
                    distFromSource[it->first] = count;
                }
            } 
            
            sort(toCheck.begin(), toCheck.end(), isCloserToSource);
        }

        cout<<"Scenario #"<<scene++<<"\n"<<distFromSource[end]<<" tons\n\n";
    }
}
