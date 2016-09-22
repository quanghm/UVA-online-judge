/*
 * =====================================================================================
 *
 *       Filename:  315.cpp
 *
 *    Description:  Network
 *
 *        Version:  1.0
 *        Created:  09/07/2016 17:32:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<cstdio>
#include<vector>
using namespace std;

int root(int i, int *id){
    while (id[i]!=id[id[i]]){
        id[i] = id[id[i]];
        i=id[i];
    }
    return id[i];
}

int main(){
    int n, count, ans,start,end;
    int id[100];
    char ch;
    while (scanf("%d",&n) && n){
        ans = 0;

        vector<vector<int> > edges(100);

        while (scanf("%d",&start)&&start){
            while ( (ch=getchar())!='\n'){
                scanf("%d",&end);
                edges[start].push_back(end);
                edges[end].push_back(start);
            }        
        }

        for (int c=1; c<=n; c++){
            // re-init:
            for (int i = 1; i<=n; i++) id[i]=i;
            count = n-1;
            
            for (int i=1; i<=n; i++){
                if (i==c) continue; // id disabled
                start = root(i,id);
                for (vector<int>::iterator it=edges[i].begin();
                        it!=edges[i].end(); it++){
                    if (*it==c) continue;
                    end = root(*it,id);
                    if (start !=end){
                        count--;
                        id[end]=start;
                    }
                }
            }
            if (count>1) ans++;
        }

        printf("%d\n",ans);
    }
}


