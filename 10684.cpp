/*
 * =====================================================================================
 *
 *       Filename:  10684.cpp
 *
 *    Description:  The Jackpot -- Max Subarray
 *
 *        Version:  1.0
 *        Created:  08/25/2016 15:34:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;

    long long maxEndHere, maxSoFar, temp;
    while (cin>>n && n){
        maxEndHere=0, maxSoFar=0;

        for (size_t i=0; i<n; ++i){
            cin >> temp;
            if (maxEndHere > -temp) {
                maxEndHere +=temp;
            } else{
                maxEndHere = 0;
            }

            if (maxEndHere>maxSoFar) maxSoFar = maxEndHere;
        }

        if (maxSoFar){
            cout<<"The maximum winning streak is "<<maxSoFar<<".\n";
        } else{
            cout<<"Losing streak.\n";
        }
    }
}

