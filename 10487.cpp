/*
 * =====================================================================================
 *
 *       Filename:  10487.cpp
 *
 *    Description:  Closet sum
 *
 *        Version:  1.0
 *        Created:  09/09/2016 22:25:40
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
    int n,m,s,lastSum, lastDiff,sum,c=1;
    int l,r;

    while (cin>>n && n){
        // read the numbers in
        vector<int> nums(n);
        for (int i=0; i<n; i++){
            cin>> nums[i];
        }
        
        sort(nums.begin(),nums.end());

        cin>>m;
        cout<<"Case "<<c++<<":\n";

        while (m--){
            l=0,r=n-1,lastSum=nums[0]+nums[n-1];
            cin>>s;
            lastDiff = (lastSum>s)?(lastSum-s):(s-lastSum);

            while (l<r){
                sum = nums[l]+nums[r];
                if (sum==s) {
                    lastSum=s;
                    break;
                }
                if (sum < s){
                    l++;
                    if (s<sum+lastDiff){
                        lastSum=sum;
                        lastDiff=s-sum;
                    }
                } else {
                    r--;
                    if (sum < lastDiff + s){
                        lastSum  = sum;
                        lastDiff = sum-s;
                    }
                }
            }
            cout<<"Closest sum to "<<s<<" is "<<lastSum<<".\n";
        }
    }
}
