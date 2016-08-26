/*
 * =====================================================================================
 *
 *       Filename:  10714.cpp
 *
 *    Description:  Ants
 *
 *        Version:  1.0
 *        Created:  08/23/2016 11:52:16
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
#define inf 10e7
int main(){
    int numCases, numAnts, antPos, otherPos, min, max, length;

    cin>>numCases;

    while (numCases--){
        min = 0, max = 0;
        cin >> length >> numAnts;

        while (numAnts--){
            cin >> antPos;
            otherPos = length - antPos;
            if (antPos > otherPos){
                if (max < antPos) max = antPos;
                if (min < otherPos) min = otherPos;
            } else{
                if (max < otherPos) max = otherPos;
                if (min < antPos) min = antPos;
            }

        }

        cout<<min<< " "<<max<<"\n";
    }
}
