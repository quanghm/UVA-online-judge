/*
 * =====================================================================================
 *
 *       Filename:  10849.cpp
 *
 *    Description:  Move the bishop
 *
 *        Version:  1.0
 *        Created:  08/22/2016 17:32:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>

using namespace std;

int main(){
    int c, t, n, r1, c1, r2, c2, diff1, diff2;
    cin>>c;

    while (c--){
        cin>>t>>n;
        while (t--){
            cin>>r1>>c1>>r2>>c2;
            if (r1<=0 || r1>n || c1<=0 || c1>n ||12<= 0 || c2<=0 || r2>n || c2>n){
                cout<<"no move\n";
                continue;
            }
            diff1 = r1-c1, diff2 = r2-c2;
            if (r1==r2 && c1==c2){
                cout<<"0\n";
            } else if (r1+c1==r2+c2 || diff1==diff2){
                cout<<"1\n";
            } else if ( (diff1&1)==(diff2&1) ){
                cout<<"2\n";
            } else {
                cout<<"no move\n";
            }
        }
    }
}
