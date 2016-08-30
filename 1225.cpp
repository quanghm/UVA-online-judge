/*
 * =====================================================================================
 *
 *       Filename:  1225.cpp
 *
 *    Description:  Digit counting
 *
 *        Version:  1.0
 *        Created:  08/29/2016 17:37:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>

using namespace std;

int main(){
    int n, numCases, digit;
    int counts[10000][10]={};

    for (int i = 1; i<10000; i++){
        n = i;

        for (int j = 0; j<10; j++){
            counts[i][j] = counts[i-1][j];
        }
        while (n){
            digit = n % 10;
            n /= 10;
            counts[i][digit]++;
        }
    }

    cin>>numCases;
    while (numCases--){
        cin>>n;

        for (digit=0;digit<9;digit++){
            cout<<counts[n][digit]<<" ";
        }
        cout<<counts[n][9]<<"\n";
    }
}
