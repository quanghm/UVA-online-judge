/*
 * =====================================================================================
 *
 *       Filename:  291.cpp
 *
 *    Description:  Santa's House
 *
 *        Version:  1.0
 *        Created:  08/31/2016 14:03:36
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

using namespace std;

vector<vector<int> > findPath(vector<vector<bool> > &graph, int start, int numEdge){
    vector<vector<int > > r;

    if (numEdge==0){
        if (start == 1){
            r.push_back(vector<int>(1,2) );
            return r;
        } else{
            return r;
        }
    }

    for (int i = 0; i < 5; i++){
        if (graph[i][start]){
            numEdge--, graph[i][start]=0, graph[start][i]=0; // mark edge as removed, reduce numEdge
            vector<vector<int> > v = findPath(graph,i,numEdge);

            // attach answer
            for (vector<vector<int> >::iterator it = v.begin(); 
                    it!=v.end(); it++){
                r.push_back(*it);
                (r.back()).push_back(start+1);
            }

            // restore the graph
            numEdge++, graph[i][start]=1, graph[start][i]=1;
        }
    }
    return r;
}
int main(){
    vector<vector<bool> > graph(5, vector<bool>(5,0) );
    graph[0][1] = 1, graph[0][2] = 1, graph[0][4] = 1;
    graph[1][0] = 1, graph[1][2] = 1, graph[1][4] = 1;
    graph[2][0] = 1, graph[2][1] = 1, graph[2][3] = 1, graph[2][4]=1;
    graph[3][2] = 1, graph[3][4] = 1;
    graph[4][0] = 1, graph[4][1] = 1, graph[4][2] = 1, graph[4][3] =1;

    //
    vector<vector<int> > u = findPath(graph, 0, 8);

    for (vector<vector<int> >::iterator it = u.begin(); 
            it!=u.end(); it++){
        for (vector<int>::reverse_iterator rit = (*it).rbegin();
                rit!=(*it).rend(); rit++){
            cout<<*rit;
        }
        cout<<"\n";
    }
}

