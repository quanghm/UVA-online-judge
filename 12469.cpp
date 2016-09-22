/*
 * =====================================================================================
 *
 *       Filename:  12469.cpp
 *
 *    Description:  Stones -- recursive
 *
 *        Version:  1.0
 *        Created:  08/15/2016 23:46:52
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
    bool ans[1001]={};  // if Alicia wins, i.e. the first player wins
    int n=2,prev=1, next;

    ans[1]=1;
    while (n<1000){
        ans[n]=1;
        next = prev+n;
        prev = n;
        n=next;
    }

    while (cin>>n &&n){
        if (ans[n]){
            cout<<"Roberto\n";
        } else{
            cout<<"Alicia\n";
        }
    }

}
