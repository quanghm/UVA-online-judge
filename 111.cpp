/*
 * =====================================================================================
 *
 *       Filename:  111.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 13:55:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    int L, lo, hi, mid;

    int c[21];
    int r[21];
    int lcs[21][21] = {};
        

    // read the orders
    for (int i=1;i<=n;++i){
        cin>>tmp;
        c[tmp]=i;
    }


    for(;;){
        if (!(cin>>tmp)) break;
        r[tmp]=1;
        for (int i = 2; i<=n; ++i){
            cin >>tmp;
            r[tmp] = i;
        }

        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=n; j++){
                tmp = (lcs[i-1][j]>lcs[i][j-1])?
                      lcs[i-1][j]:lcs[i][j-1];
                if (c[i] == r[j]){
                    lcs[i][j] = (tmp >lcs[i-1][j-1])?
                                 tmp : (lcs[i-1][j-1]+1);
                } else {
                    lcs[i][j] = tmp;
                }
            }
        }
        cout<<lcs[n][n]<<"\n";
    }
}
