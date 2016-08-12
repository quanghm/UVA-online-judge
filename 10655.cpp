/*
 * =====================================================================================
 *
 *       Filename:  10655.cpp
 *
 *    Description:  Contemplation! Algebra
 *
 *        Version:  1.0
 *        Created:  08/12/2016 11:38:35
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

using namespace std;

int main(){
    long long s, p,n;

    while (cin>> s >> p >> n){
        if (s==0 && p==0){
            cout<<"0\n";
        } else if (s==1 && p==0){
            cout<<"1\n";
        } else if (n==0){
            cout <<"2\n";
        } else if (n==1){
            cout<< s<<"\n";
        } else {
            long long u2=2, u1=s, u,temp;
            int a=1;
            while (a++<n){
                temp=u;
                u = u1*s - u2*p;
                u2=u1;
                u1=temp;
            }
            cout<< u<<"\n";
        }
    }
}
