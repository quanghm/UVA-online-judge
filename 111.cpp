/*
 * =====================================================================================
 *
 *       Filename:  111.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 13:55:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    int L, lo, hi, mid;

    int c[21];
    int r[20];

    // read the orders
    for (int i=1;i<=n;++i){
        cin>>tmp;
        c[i]=tmp;
    }

    while (1){
        for (int i = 0; i<n; ++i){
            cin >>r[i];
            cout << r[i] << " ";
        }

        cout << "\n";
        L = 0;

        int m[21]={}; // indexes
        for (int i = 0;i <n;i++){
            lo = 1;
            hi = L;

            while (lo <= hi){
                mid = (lo + hi+1)/2;
                if (r[c[m[mid]]] < r[c[i]]){
                    lo = mid+1;
                } else{
                    hi = mid-1;
                }
                cout<< "i:" << i << " --- "  << lo << " " << mid << " "<< hi <<"\n";
            }
            
            m[lo]=i;

            // lo = length r[i]
            if (lo > L) {
                L = lo;
            }
        }

        cout << L << "\n";
        if (cin.eof()) break;
    }
}
