/*
 * =====================================================================================
 *
 *       Filename:  10905.cpp
 *
 *    Description:  Children's Game
 *
 *        Version:  1.0
 *        Created:  09/13/2016 17:35:47
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
vector<string> nums(50);

bool compare(int i, int j){
    if (i==j) return false;
    string::iterator i1=nums[i].begin();
    string::iterator i2=nums[j].begin();
    int ii=0;

    while (i1!=nums[j].end() && *i1==*i2&&ii++<20){
        i1++,i2++;
        if (i1==nums[i].end()) i1=nums[j].begin();
        if (i2==nums[j].end()) i2=nums[i].begin();
    }
    return (i1!=nums[j].end() && *i1<*i2);
}
int main(){
    int n;
    vector<int> index(50);
    while (cin>>n && n){
        for (int i=0;i<n; i++){
            cin>>nums[i];
            index[i]=i;
        }

        sort(index.begin(),index.begin()+n,compare);

//        cout<<"here\n";
        while(n--){
            cout<<nums[index[n]];
        }
        
        cout<<"\n";
    }
}
