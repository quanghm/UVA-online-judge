/*
 * =====================================================================================
 *
 *       Filename:  12459.cpp
 *
 *    Description:  Bees' ancestors
 *
 *        Version:  1.0
 *        Created:  08/12/2016 14:43:04
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
    unsigned long long f[81]={};
    f[0]=1,f[1]=1;

    for (int i=2;i<81;++i){
        f[i]=f[i-1]+f[i-2];
    }

    int i;
    while (cin>>i && i){
        cout<<f[i]<<"\n";
    }
}
