/*
 * =====================================================================================
 *
 *       Filename:  839.cpp
 *
 *    Description:  Not so Mobile
 *
 *        Version:  1.0
 *        Created:  08/28/2016 05:44:14
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
#include <utility>

using namespace std;

pair<long long, bool> isBalance(){
    int wl, dl, wr, dr;
    pair<long long, bool> temp;
    bool balance=true;

    cin >> wl >> dl >> wr >> dr;

    if (wl == 0){ // read the left sub-mobile
        temp = isBalance();
        wl = temp.first;
        balance = temp.second;
    }

    if (wr == 0){ // read the second sub-mobile
        temp = isBalance();
        wr = temp.first;
        balance = balance && temp.second;
    }

    temp.first = wl + wr;
    temp.second = balance && (wl*dl == wr*dr);

    return temp;
}

int main(){
    int n;
    cin >>n;
    for(;;){
        if (isBalance().second){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        if (--n) {
            cout<<"\n";
        } else {
            break;
        }
    }
}
