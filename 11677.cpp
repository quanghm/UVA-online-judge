/*
 * =====================================================================================
 *
 *       Filename:  11677.cpp
 *
 *    Description:  Alarm Clock
 *
 *        Version:  1.0
 *        Created:  09/02/2016 11:41:53
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
    int h1, m1, h2, m2, d1, d2;
    while (cin>>h1>>m1>>h2>>m2 && (h1 || m1 || h2 || m2)){
        d2= m2 - m1;
        if (d2 < 0){
            d1 = -1;
            d2 +=60;
        } else {
            d1=0;
        }
        d1 += (h2-h1);
        if (d1<0) d1+=24;
        d2 += d1*60;
        cout<<d2<<"\n";
    }
}

