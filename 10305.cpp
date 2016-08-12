/*
 * =====================================================================================
 *
 *       Filename:  10305.cpp
 *
 *    Description:  Ordering Task
 *
 *        Version:  1.0
 *        Created:  08/10/2016 09:37:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;
void visit( int i,
            vector<bool> &isVisited,
            vector<vector<int> > &edges,
            stack<int> &q);

int main(){
    int n, m,i,j;

    while (scanf("%d %d",&n, &m) && n){
        vector<vector<int> > edges(n+1);
        vector<bool> isVisited(n+1,0);
        stack<int>  q;

        for (int ii = 0; ii<m; ++ii){
            scanf("%d %d",&i,&j);
            edges[i].push_back(j);
        }
        
        // depth-first
        for (int ii = 1; ii<=n; ++ii){
            if (isVisited[ii]) continue;

            visit(ii,isVisited, edges, q);
        }

        while (1){
            i = q.top();
            q.pop();
            if (q.empty()){
                printf("%d\n", i);
                break;
            } else{
                printf("%d ",i);
            }
        }
    }
}

void visit(int i, 
           vector<bool> &isVisited, 
           vector<vector<int> > &edges,
           stack<int> &q){ 
//    if (edges[i].size()==0){ q.push(i);return;}
    if (isVisited[i]) return;
    
    for (vector<int>::iterator it = edges[i].begin();
        it!= edges[i].end(); ++it){
        visit(*it,isVisited, edges, q);
    }
    
    isVisited[i]=1;
    q.push(i);
}
