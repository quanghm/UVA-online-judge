/*
 * =====================================================================================
 *
 *       Filename:  12646.cpp
 *
 *    Description:  Zero or One
 *
 *        Version:  1.0
 *        Created:  09/03/2016 20:51:22
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
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,b;

    char winner[8] = {'*','A','B','C','C','B','A','*'};
    while (cin>> n){
        cin >> b;
        if (b) n+=2;
        cin >> b;
        if (b) n+=4;

        cout<<winner[n]<<"\n";
    }
}
