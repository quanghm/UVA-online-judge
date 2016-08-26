/*
 * =====================================================================================
 *
 *       Filename:  437.cpp
 *
 *    Description:  The tower of Babylon -- Longest Path in a DAG
 *
 *        Version:  1.0
 *        Created:  08/18/2016 10:41:13
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
#include <algorithm>
 
using namespace std;
 
int blocks[90][3] = {};
 
bool isSmaller(int i, int j){
    return (blocks[i][0] < blocks[j][0] 
            && blocks[i][1] < blocks[j][1]);
}
 
void visit(int i, vector<int> &order, 
            vector<vector<int> > &edges,
            vector<bool> &isVisited){
    if (isVisited[i]) return;
 
    for (vector<int>::iterator it = edges[i].begin();
            it != edges[i].end(); ++it){
        visit(*it, order, edges, isVisited);
    }
 
    order.push_back(i);
    isVisited[i] = 1;
}
int main(){
    int n,c=1;;
    vector<int> temp(3);
    while (scanf("%d",&n) && n){
        for (int i=0, blockNum=0; i<n; ++i){
            scanf("%d%d%d", &(temp[0]), &(temp[1]),&(temp[2]));
            sort(temp.begin(),temp.end());
            blocks[blockNum][0]=temp[1], blocks[blockNum][1] = temp[2]; blocks[blockNum++][2] = temp[0];
            blocks[blockNum][0]=temp[0], blocks[blockNum][1] = temp[2], blocks[blockNum++][2] = temp[1];
            blocks[blockNum][0]=temp[0], blocks[blockNum][1] = temp[1], blocks[blockNum++][2] = temp[2];
        } 
 
        // new number of blocks
        n *= 3; 
 
        // new local arrays
        vector<int> order;
        vector<int> tallestToHere(n,0);
        vector<bool> isVisited(n,0);
        vector<vector<int> > edges(n);
 
        // creat edges:
        for (int i = 0; i<n; ++i){
            for (int j = 0; j<n; ++j){
                if (isSmaller(i,j)){
                    edges[i].push_back(j);
                }
            }
        }
 
        // sort graph:
        for (int i=0; i<n; ++i){
            visit(i, order, edges, isVisited);
        }
 
//         for (int i =0; i<n; ++i){
//             printf("%d %d %d\n",blocks[order[i]][0], blocks[order[i]][1], blocks[order[i]][2]);
//         }
         
//         for (int i = 0;i<n; ++i){
//             printf("%d ",order[i]);
//         } 
//         printf("\n---\n");
        int maxHeight = 0;
        int tmp;
 
        // run through graph:
        int i = 0; 
        while (i<n){
            tmp=0;
            for (vector<int>::iterator it = edges[order[i]].begin();
                   it != edges[order[i]].end(); ++it){
               if (tmp < tallestToHere[*it]){
                    tmp  = tallestToHere[*it];
               }
            }
          
            if (blocks[order[i]][2]>0){
                tmp += blocks[order[i]][2];
            }
            
            tallestToHere[order[i]] = tmp;
            if (maxHeight < tmp) maxHeight=tmp;
          
            //printf("i: %d, max: %d\n",order[i],tmp);
            i++;
        }
 
        printf("Case %d: maximum height = %d\n", c++, maxHeight);
     
    }
}
