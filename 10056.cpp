/*
 * =====================================================================================
 *
 *       Filename:  10056.cpp
 *
 *    Description:  What is the Probability
 *
 *        Version:  1.0
 *        Created:  08/12/2016 14:15:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<cmath>
#include<iostream>
#include <cstdio>
using namespace std;

int main(){
    int s,n,i;
    double p,q;
    
    cin>>s;
    while (s--){
        cin>>n>>p>>i;
        if (p==0){
            cout<<"0.0000\n";
        } else if (p==1){
            if (i>1) {
                cout<<"0.0000\n";
            } else {
                cout<<"1.0000\n";
            }
        } else{
            q=1-p;
            printf("%0.4lf\n",pow(q,i-1)*p/(1-pow(q,n)));
        }
    }
}
