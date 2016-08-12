/*
 * =====================================================================================
 *
 *       Filename:  11805.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/2016 15:41:09
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
    int t, n, k, p;

    cin>> t;

    for (int i = 1; i<=t; ++i){
        cin >> n >> k >> p;
        p = (p+k)%n;
        if (!p) {p=n;}
        cout << "Case "<< i<< ": "<< p<<"\n";
    }
}
