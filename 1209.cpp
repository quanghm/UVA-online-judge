/*
 * =====================================================================================
 *
 *       Filename:  1209.cpp
 *
 *    Description:  Wordfish
 *
 *        Version:  1.0
 *        Created:  09/05/2016 16:48:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int position[128]; // contain position of the characters

    string line, buff,ans;
    int dist,minDist, largestDist;

    int i;

    long long index; // index of the username
    while (getline(cin,line)){
        largestDist = -1;
        vector<string> neighborhood(21);
        ans="";

        buff=line;
        for (i=10; i< 21;i++){
            neighborhood[i] = (buff);
            next_permutation(buff.begin(),buff.end());
        }

        buff=line;
        i=10;
        while (i--){
            prev_permutation(buff.begin(),buff.end());
            neighborhood[i]=buff;
        }
        
        sort(neighborhood.begin(),neighborhood.end());

        for (vector<string>::iterator sit = neighborhood.begin(); 
                sit !=neighborhood.end(); sit++){
            minDist = 27;
            // compute mindist
            for (string::iterator it = (*sit).begin()+1; it!=(*sit).end(); it++){
                dist = *it - *(it-1);
                if (dist<0) dist = -dist;
                if (dist<minDist) minDist = dist;
            }

            // get the largest dist
            if (largestDist<minDist){
                largestDist=minDist;
                ans=*sit;
            }
        }

        cout<< ans<<largestDist<<"\n";
    }
}
