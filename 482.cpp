/*
 * =====================================================================================
 *
 *       Filename:  482.cpp
 *
 *    Description:  Permutation Arrays
 *
 *        Version:  1.0
 *        Created:  09/08/2016 22:12:28
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
#include <vector>
#include <string>

using namespace std;

int ordering[1000000];

int main(){
    int t,n,temp;

    cin>>t;
    getchar(), getchar();
    for (;;){
        n=0;
        char ch=0;

        while (ch!='\n'){
            n++;
            scanf("%d",ordering+n);
            ch=getchar();
        }

        vector<string> u(n+1);

        for (int i=1;i<=n;i++){
            cin>>u[ordering[i]];
        }
        for (int i=1;i<=n;i++){
            cout<<u[i]<<"\n";
        }

        if (--t){
            cout<<"\n";
        } else{
            break;
        }

    }

}

