/*
 * =====================================================================================
 *
 *       Filename:  12403.cpp
 *
 *    Description:  Save Shetu
 *
 *        Version:  1.0
 *        Created:  08/25/2016 14:13:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    long long t, k, sum =0;
    string s;

    cin>>t;

    while (t--){
        cin>>s;
        if (s == "donate"){
            cin>> k;
            sum += k;
        } else{
            cout<<sum<<"\n";
        }
    }
}
