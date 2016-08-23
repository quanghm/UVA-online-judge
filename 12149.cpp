/*
 * =====================================================================================
 *
 *       Filename:  12149.cpp
 *
 *    Description:  Feynman 
 *
 *        Version:  1.0
 *        Created:  08/17/2016 05:22:08
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

int main(){
    int n;
    int sq[101];

    sq[1]=1;

    for (n=2;n<101;n++){
        sq[n] = sq[n-1] + n*n;
    }
    
    while (cin>>n&&n){
        cout<<sq[n]<<"\n";
        // note: sq[n] = 1*1 + 2*2 + ... + n*n
    }
}
