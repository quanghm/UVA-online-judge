/*
 * =====================================================================================
 *
 *       Filename:  507.cpp
 *
 *    Description:  Jill Rides Again -- max subarray sum
 *
 *        Version:  1.0
 *        Created:  09/12/2016 16:35:27
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

int main(){
    int numCases, numStops, buff,route=1;

    int maxEndingHere, maxEndingHereStart, maxSoFar, maxSoFarStart, maxSoFarEnd;

    cin>>numCases;

    while (numCases--){
        cin>> numStops;
        maxEndingHere=0,maxSoFar=0,maxSoFarStart=1,maxEndingHereStart=1;

        for (int i=1; i<numStops; i++){
            cin>>buff;
            if (maxEndingHere < -buff){ // restart at 0
                maxEndingHere = 0;
                maxEndingHereStart=i+1;
            } else {
                maxEndingHere = maxEndingHere+buff;
            }

            if (maxSoFar<maxEndingHere){
                maxSoFar = maxEndingHere;
                maxSoFarStart = maxEndingHereStart;
                maxSoFarEnd = i;
            } else if (maxSoFar==maxEndingHere){
                if (maxSoFarEnd-maxSoFarStart < i-maxEndingHereStart){
                    maxSoFarStart = maxEndingHereStart;
                    maxSoFarEnd = i;
                }
            }
        }

        if (maxSoFar){
            cout<< "The nicest part of route "<<route++ << " is between stops "
                << maxSoFarStart<< " and " << maxSoFarEnd+1<<"\n";
        } else{ 
            cout<< "Route " << route++ << " has no nice parts\n";
        }

    }
}
