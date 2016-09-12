/*
 * =====================================================================================
 *
 *       Filename:  10611.cpp
 *
 *    Description:  The Playboy Chimp
 *
 *        Version:  1.0
 *        Created:  09/06/2016 11:52:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int ladies[50000];

    int n, q, h;
    int lo, mid, hi;

    cin>>n;

    for (int i = 0; i<n; i++){
        cin>> ladies[i];
    }

    cin >> q;

    while (q--){
        cin >> h; // height
        lo = 0, hi =n;

        if (ladies[0]>=h){
            cout<<"X ";
        } else{
            // search for highest smaller than h

            while (lo < hi){
                mid = (lo+hi)/2;

                if (h > ladies[mid]){
                    lo = mid+1;
                } else { // ladies[mid]>= h
                    hi = mid;
                }
            }
            if (ladies[lo]<h){
                cout<<ladies[lo]<<" ";
            } else {
                cout<<ladies[lo-1]<<" ";
            }
        }

        if (ladies[n-1]<=h){ // taller than all
            cout<<"X\n";
        } else {  // shortest higher than h
            hi = n;

            while (lo < hi){
                mid = (lo+hi)/2;

                if (h < ladies[mid]){
                    hi = mid;
                } else {
                    lo = mid+1;
                }
            }

            if (ladies[hi]>h){
                cout<<ladies[hi]<<"\n";
            } else {
                cout<<ladies[hi+1]<<"\n";
            }
        }
    }
}
