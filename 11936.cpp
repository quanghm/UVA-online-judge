/*
 * =====================================================================================
 *
 *       Filename:  11936.cpp
 *
 *    Description:  The Lazy Lumberjacks
 *
 *        Version:  1.0
 *        Created:  09/08/2016 23:53:45
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
    int n;
    vector<long long> edges(3);

    cin>> n;

    while (n--){
        for (int i=0;i<3;++i){
            cin>>edges[i];
        }
        sort(edges.begin(), edges.end());

        if (edges[0] + edges[1]<=edges[2]){
            cout<<"Wrong!!\n";
        } else {
            cout<<"OK\n";
        }
    }


}
