/*
 * =====================================================================================
 *
 *       Filename:  12247.cpp
 *
 *    Description:  Jollo
 *
 *        Version:  1.0
 *        Created:  08/28/2016 07:30:31
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

vector<int> card(5);
void leastNotDealt(int i){
    bool isDealt[53] = {};
    for (int i = 0 ; i<5; i++){
        isDealt[card[i]] = 1;
    }

    int j = i;
    while (j<53 && isDealt[j]){
        j++;
    }
    if (j<53){
        cout<<j<<"\n";
    } else{
        cout<<"-1\n";
    }
}
int main(){
    while ((cin>>card[0]>>card[1]>>card[2]>>card[3]>>card[4]) 
            && card[0]){
        sort(card.begin(),card.begin()+3);
        sort(card.begin()+3, card.end());

//        for(int i = 0; i<5;i++){
//            cout<<card[i]<<" ";
//        }
//        cout<<"\n";
        // b0 < s1 && b1 < s2
        if (card[3]<card[1] && card[4] < card[2])
        {
            cout<<"-1\n";
            continue;
        }

        // b0 < s1 < s2 < b1
        if (card[3]<card[1]){
            leastNotDealt(card[2]);
            continue;
        } 

        // s2 < b0 < b1
        if (card[3]>card[2]){
            leastNotDealt(1);
            continue;
        }
        
        //  s1 < b0 < s2 < b1
        leastNotDealt(card[1]);
    }
}
