/*
 * =====================================================================================
 *
 *       Filename:  12908.cpp
 *
 *    Description:  The Book Thief -- Binary search
 *
 *        Version:  1.0
 *        Created:  08/29/2016 10:17:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;
#define N 14143

int main(){
    int s,k,triNums[N], hi,lo,mid;

    for (int i = 1; i<N; ++i){
        triNums[i] = triNums[i-1]+i;
    }

    while (cin>> s && s){
        // binary search triNums for s
        lo=0,mid=0,hi=N;
        while (lo<hi){
//            cout<<lo<<"--"<<hi<<"\n";
            mid = (lo + hi)/2;
            if (s == triNums[mid]){
                break;
            } else if (s < triNums[mid]){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        if (s==triNums[mid]){
            mid++;
            cout<<mid<<" "<<mid<<"\n";
        } else {
            cout<<triNums[hi]-s<<" "<<hi<<"\n";
        }
    }    
}
