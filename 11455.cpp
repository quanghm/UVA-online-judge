/*
 * =====================================================================================
 *
 *       Filename:  11455.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2016 19:19:32
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

int main(){
    int t;
    vector<int> e(4);
    
    cin >> t;
    while (t--){
        for (int i=0;i<4;++i){
            cin>>e[i];
        }
        sort(e.begin(),e.end());

        if (e[0]==e[3]){
            cout<<"square\n";
        } else if (e[0]==e[1]&& e[2]==e[3]){
            cout<<"rectangle\n";
        } else if (e[0]+e[1]+e[2]> e[3]){
            cout<<"quadrangle\n";
        } else {
            cout<<"banana\n";
        }
    }
}
