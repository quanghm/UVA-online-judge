/*
 * =====================================================================================
 *
 *       Filename:  10474.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 16:46:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, Q,temp,c=0;

    while ((cin>>N>>Q)&& (N || Q)){
        cout<< "CASE# "<<++c<<":\n";
        vector<int> marbles(N);
        // read numbers in
        for (int i= 0; i< N;i++){
            cin >> marbles[i];
//            cout << marbles[i]<<" ";
        }
//        cout<<"\n---\n";

        // sort numbers
        sort(marbles.begin(),marbles.end());

        // search for each c
        while(Q--){
            cin >> temp;
            int lo=0,hi=N,mid;
            while(lo<=hi){
                mid = (lo+hi)/2;
               // if (temp == marbles[mid]){
               //     cout<< temp << " found at "<<mid+1<<"\n";
               //     break;
               // } else 
                if (temp > marbles[mid]){
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            
            }

            if (temp==marbles[lo]){
                cout<< temp << " found at "<<lo+1<<"\n";
            } else if (lo>hi){
                cout<<temp<< " not found\n";
            }
        }
    }
}
