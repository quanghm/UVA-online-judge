/*
 * =====================================================================================
 *
 *       Filename:  12938.cpp
 *
 *    Description:  Just Another Easy Problem
 *
 *        Version:  1.0
 *        Created:  09/03/2016 19:43:48
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

using namespace std;

int main(){
    vector<vector<int> > squares(68,vector<int>(4));

    int n=32,sq,dis;

    for (vector<vector<int> >::iterator it=squares.begin(); n<100; n++,it++){
        sq = n*n;
        for (int i = 0; i<4; i++){
            (*it)[i] = sq % 10;
            sq /= 10;
        }
    }

    int answers[10000]={};

    for (n=1000; n<10000; n++){
        for (vector<vector<int> >::iterator it = squares.begin();
                it !=squares.end();it++){
            sq = n, dis =0;
            for (int j = 0; j<4; j++){
                if (sq % 10 == (*it)[j]){
                    dis++;
                }
                sq/=10;
            }
            if (dis==3) answers[n]++;
        }
    }

    cin>>sq;
    dis = 0;
    
    while (dis++<sq){
        cin>>n;
        cout<<"Case "<<dis<<": "<< answers[n]<< "\n";
    }
}
