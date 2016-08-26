/*
 * =====================================================================================
 *
 *       Filename:  10178.cpp
 *
 *    Description:  Count the Faces
 *
 *        Version:  1.0
 *        Created:  08/24/2016 08:45:17
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
#include <map>
using namespace std;

int main(){
    int numVertices, numEdges;
    char n1, n2;

    while (cin>> numVertices >> numEdges){
        map<char,int> degree;  // degree of a vertex
        vector<vector<int> > edges(123);
        queue<int> leaves;

        for (int i=0; i<numEdges; i++){
            cin >> n1 >> n2;

            degree[n1]++, degree[n2]++;
            edges[n1].push_back(n2), edges[n2].push_back(n1);
        }

        // build queue of leaves
        for (int i=0; i<52; ++i){
            if (degree[i] == 1){
                leaves.push(i);
            }
        }

        // remove leaves
        while (!leaves.empty()){
            n1 = leaves.front();
            leaves.pop();

            // if is a single node
            if (degree[n1]==0){
                numVertices--;
            }

            // if still a leave, remove the edge
            if (degree[n1]==1){
                numEdges--,numVertices--;
                degree[n1] = 0;

                // update the degree of the other vertex
                for (vector<int>::iterator it = edges[n1].begin();
                        it != edges[n1].end(); it++){
                    if (degree[*it]) (degree[*it]--);

                    if (degree[*it]==1){
                        leaves.push(*it);
                    }
                }
            }
        }

        // counting connected component
        int numComponents = numVertices;
        map<char, char> root;

        // create root
        for (map<char,int>::iterator it = degree.begin();
                it!=degree.end(); ++it){
            if (it->second){
                root[it->first] = it->first;
            }
        }

        // update root
        for (map<char,char>::iterator it= root.begin();
                it!=root.end(); ++it){
            n1 = it->second;
            for (vector<int>::iterator iit = edges[it->first].begin();
                    iit != edges[it->first].end(); iit++){
                n2 = root[*iit];
                
                // if different component
                if (degree[*iit] && (n2!=n1)){
                    numComponents --;

                    for (map<char,char>::iterator itt = root.begin();
                            itt != root.end(); ++itt){
                        if (itt->second == n2) itt->second = n1;
                    }
                }
            }
        }

        cout << (numEdges + numComponents + 1 - numVertices) <<"\n";
    }
    return 0;
}
