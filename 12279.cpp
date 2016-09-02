/*
 * =====================================================================================
 *
 *       Filename:  12279.cpp
 *
 *    Description:  Emoogle Balance
 *
 *        Version:  1.0
 *        Created:  09/02/2016 16:24:07
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
    int n, c=1, num, reason;
    while (cin>>n &&n){
        num =0;
        while (n--){
            cin>> reason;
            if (reason) {num++;} else{ num--;}
        }
        cout<<"Case "<<c++<<": "<<num<<"\n";
    }
}
