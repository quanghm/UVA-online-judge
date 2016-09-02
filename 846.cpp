/*
 * =====================================================================================
 *
 *       Filename:  846.cpp
 *
 *    Description:  Steps
 *
 *        Version:  1.0
 *        Created:  08/30/2016 16:56:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long t, x, y, ans;
    cin>> t;
    while (t--){
        cin>> x>> y;
        y -= x;
        if (y<4){
            cout<<y<<"\n";
            continue;
        }
        x = (long long)(sqrt(y));
        ans = y - x*x;

        if (ans ==0){
            cout<<(2*x-1)<<"\n";
        } else if (ans <= x){
            cout<< 2*x<<"\n";
        } else {
            cout<< 2*x +1 <<"\n";
        }
    }
}
