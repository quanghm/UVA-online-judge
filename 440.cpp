/*
 * =====================================================================================
 *
 *       Filename:  440.cpp
 *
 *    Description:  Eeny Meeny Moo
 *
 *        Version:  1.0
 *        Created:  09/02/2016 15:09:12
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

int getSmallest(int i){
    int k=2, start,j;

    for (;;){
        start=0, j=i-1;
        for (;j>1;j--){
            start = (start + k - 1)%j;
            if (start==0)    break;
        }
        if (j>1) {
            k++;
        } else{
            return k;
        }
    }
}

int main(){
    int val[150];
    int n;

    for (int i =3; i<150; i++){
        val[i] = getSmallest(i);
    }
    
    while (cin>>n &&n){
        cout<< val[n]<<"\n";
    }
}
