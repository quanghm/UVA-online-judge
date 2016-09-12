/*
 * =====================================================================================
 *
 *       Filename:  10338.cpp
 *
 *    Description:  Mischievous Children
 *
 *        Version:  1.0
 *        Created:  09/10/2016 10:10:23
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
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int numCases,c=0;
    string line;
    unsigned long long f[21]={}, ans;

    cin>>numCases;

    f[0]=1;
    for (int i=1;i<21;i++){
        f[i] = f[i-1]*i;
    } 

    while (c++<numCases){
        cin>>line;

        int count[26]={};
        for (string::iterator it = line.begin();
                it!=line.end(); it++){
            count[*it-'A']++;
        }

        ans=f[line.length()];
        for (int i=0; i<26; i++){
            ans /= f[count[i]];
        }
       
        cout<<"Data set "<<c<<": "<<ans<<"\n"; 
    }
}
