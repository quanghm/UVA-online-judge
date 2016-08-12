/*
 * =====================================================================================
 *
 *       Filename:  10128.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2016 18:43:53
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
using namespace std;

long long f(int n, int p, int r){
    if (n==1) return (p&&r);
    if (n+1< p+r || p==0 || r==0) return 0;
    return f(n-1,p,r)*(n-2) + f(n-1,p-1,r) + f(n-1,p,r-1);
}
int main(){
    int t,n,p,r;
    long long ff[14][14][14];
    for (p=0;p<14;++p){
        for(n=0;n<14;++n){
            ff[n][p][0]=0;
            ff[n][0][p]=0;
        }
    }
    ff[1][1][1]=1;

    for (n=0;n<14;++n){
        for (p=1;p<14;++p){
            for (r=1;r<14;++r){
                if (n==1){
                    ff[n][p][r]=p&&r;
                } else if (n+1<p+r) {
                    ff[n][p][r]=0;
                } else {
                    ff[n][p][r] = ff[n-1][p][r]*(n-2) + ff[n-1][p-1][r]+ff[n-1][p][r-1];
                }
            }
        }
    }
    cin>>t; 
    while (t--){
        cin >> n>> p>>r;
        if (n==1){
            if (p==1 && r==1) {
                cout << "1\n";
            } else{
                cout << "0\n";
            }
        } else{ 
            cout<< ff[n][p][r]<<"\n";
        }    
    }
}
