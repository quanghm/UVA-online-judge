/*
 * =====================================================================================
 *
 *       Filename:  1587.cpp
 *
 *    Description:  Box
 *
 *        Version:  1.0
 *        Created:  08/12/2016 09:46:42
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
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int a,b;
    
    for(;;){
        vector<pair<int,int> > boxes;
       
        for(int i=0;i<6;++i){
            if (cin>>a>>b){
                if (a>b){a = a ^ b; b=a^b; a=a^b;}
                boxes.push_back(pair<int,int>(a,b) );
            } else{
                return 0;
            }
        }

        sort(boxes.begin(),boxes.end());

        if (boxes[0].first==boxes[3].first && boxes[4].first==boxes[5].first 
            && boxes[5].first==boxes[0].second && boxes[0].second==boxes[1].second &&
            boxes[2].second==boxes[5].second){
            cout<<"POSSIBLE\n";
        } else {
            cout<<"IMPOSSIBLE\n";
        }
    }   
}
