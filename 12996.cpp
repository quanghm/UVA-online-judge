/*
 * =====================================================================================
 *
 *       Filename:  12996.cpp
 *
 *    Description:  Ultimate Mango Challenge
 *
 *        Version:  1.0
 *        Created:  08/12/2016 19:28:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int t,n,l;
    int numEachTypeCounts[10];
    int numEachTypeMax[10];

    scanf("%d",&t);
    for (int i=1;i<=t;++i){
        scanf("%d%d",&n,&l);
        int total = 0;
        for (int j=0;j<n;++j){
            scanf("%d",numEachTypeCounts+j);
            total+=numEachTypeCounts[j];
        }
        bool r = (total<=l);
        for (int j=0;j<n;++j){
            scanf("%d",numEachTypeMax+j);
            r = r && (numEachTypeCounts[j]<=numEachTypeMax[j]);
        }

        cout<<  "Case "<< i <<": "<<((r)?("Yes\n"):("No\n"));
    }
}
