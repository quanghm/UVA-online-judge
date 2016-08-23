/*
 * =====================================================================================
 *
 *       Filename:  1583.cpp
 *
 *    Description:  Digit Generator
 *
 *        Version:  1.0
 *        Created:  08/13/2016 16:30:52
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

using namespace std;
#define N 100001
// int gen[N]={};   // doesn't work on UVA for some reason


int main(){
    int n,s;
    vector<int> gen(N,0);
    for (int i = 1; i<N; ++i){
        n = i;
        s = n;

        while (n){
            s += n % 10;
            n /= 10;
        }
        
        if (gen[s]){
            if (gen[s] > i) gen[s]=i;
        } else {
            gen[s]=i;
        }
    }
    cin>> n;

    while (n--){
        cin>> s;
        cout << gen[s]<<'\n';
    }
}
