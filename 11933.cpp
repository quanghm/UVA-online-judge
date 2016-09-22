/*
 * =====================================================================================
 *
 *       Filename:  11933.cpp
 *
 *    Description:  Splitting number
 *
 *        Version:  1.0
 *        Created:  09/22/2016 12:09:55
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
    int n;
    while (cin>>n && n){
        vector<int> indexes;
        int i=0;

        while (n){
            if (n%2) indexes.push_back(i);
            n/=2; 
            i++;
        }
        int ans[2]={};
        bool index=0;

        for (vector<int>::iterator it = indexes.begin();
                it!=indexes.end(); it++){
            ans[index] |= (1<<(*it));
            index = !index;
        }
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
}
