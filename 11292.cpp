/*
 * =====================================================================================
 *
 *       Filename:  11292.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2016 14:38:36
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
#include<algorithm>
using namespace std;

int numHeads,numKnights;
void printSum(){
    vector<int> heads(numHeads);
    vector<int> knights(numKnights);
    for (int i = 0; i<numHeads; i++){
        cin>> heads[i];
    }
    for (int i = 0; i<numKnights; i++){
        cin>> knights[i];
    }

    sort(heads.begin(),heads.end());
    sort(knights.begin(),knights.end());
    int h=0, k=0, sum =0;

    for (;;){
        while (heads[h]> knights[k] && k < numKnights){
            k++;
        }
        if (k==numKnights){
           cout<< "Loowater is doomed!\n";
           return;
        }

        sum += knights[k];

        h++,k++;
        if (h==numHeads){
            cout<<sum<<"\n";
            return;
        }
    }
}
int main(){
    while (cin>> numHeads>> numKnights  && numHeads){
        printSum();
    }  
}
