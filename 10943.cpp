/*
 * =====================================================================================
 *
 *       Filename:  10943.cpp
 *
 *    Description:  How do you add -- dynamic programing
 *
 *        Version:  1.0
 *        Created:  09/13/2016 22:50:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
    int n,k,temp;

    int ans[101][101]={};
    for (n=0;n<101;n++){
        ans[n][1]=1;
        ans[0][n]=1;
    }
    for (n=1;n<101;n++){
        for (k=2;k<101;k++){
            temp=0;
            for (int i=0;i<=n;i++){
                temp += ans[n-i][k-1];
            }
            ans[n][k] = temp % 1000000; 
        }
    }

    while (cin>>n>>k &&n){
        cout<<ans[n][k]<<"\n";
    }
}
