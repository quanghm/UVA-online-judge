/*
 * =====================================================================================
 *
 *       Filename:  821.cpp
 *
 *    Description:  Page Hopping -- min dist
 *
 *        Version:  1.0
 *        Created:  09/13/2016 20:27:28
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
#include <queue>

using namespace std;

void findMin(int i, 
            int j, 
            vector<vector<int> > &dist,
            vector<vector<int> > &edges,
            long long &sum,
            int &numEdges){
    if (dist[i][j]) {
        sum +=dist[i][j];
        numEdges++;
        return;
    }

    queue<int> q;
    int temp,s;
    bool isInQueue[101]={};
    isInQueue[i]=1;
    q.push(i);

    while (!q.empty()){
        s=q.front(); q.pop();
        if (s==j) break;

        temp=dist[i][s]+1;
        for (vector<int>::iterator it=edges[s].begin();
                it!=edges[s].end();it++){
            if (isInQueue[*it]) continue;
            isInQueue[*it]=1;
            q.push(*it);
            if (dist[i][*it]<temp){
                dist[i][*it]=temp;
            }
        }
    }
    if (dist[i][j]){
        sum +=dist[i][j];
        numEdges++;
    }
    return;
}
int main(){
    int start, end,numEdges,c=0;
    long long sum;

    for(;;){
        scanf("%d %d", &start, &end);
        if (!start) break;

        sum=0;
        numEdges=0;
        bool isUsed[101]={};
        vector<vector<int> > dist(101,vector<int>(101,0));
        vector<vector<int> > edges(101);
        do {
            if (!isUsed[start]) {
                isUsed[start]=1;
            }
            if (!isUsed[end]) {
                isUsed[end]=1;
            }

            dist[start][end]=1;
            edges[start].push_back(end);

            scanf("%d%d",&start,&end);
        } while (start);

        for (start=1; start<101; start++){
            if (!isUsed[start]) continue;
            for (end=1; end<101; end++){
                if (!isUsed[end]||end==start) continue;
                findMin(start,end,dist,edges,sum,numEdges);
            }
        }

        printf("Case %d: average length between pages = %lld",++c,sum/numEdges);
        sum = ( (sum%numEdges)*10000 / numEdges +5)/10;
        printf(".%03lld clicks\n",sum);
    }
}
