/*
 * =====================================================================================
 *
 *       Filename:  661.cpp
 *
 *    Description:  Blowing Fuses
 *
 *        Version:  1.0
 *        Created:  09/08/2016 16:20:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
    int n, m, c, s,t=0, op,max;

    while (cin>>n>>m>>c && n){
        int cap[21] = {};
        bool isOn[21] = {};

        for (int i = 1; i<=n; i++){
            cin>>cap[i];
        }
        
        s = 0,max=0;
        while (m--){
            cin>>op;

            if (s>c){
                continue;
            }
            if (isOn[op]){// device is on
                isOn[op]=0;
                s -= cap[op];
            } else { // device is off
                s += cap[op];
                isOn[op]=1;
                if (max<s) max=s;
            }
        }
        
        if (s>c){
            cout<<"Sequence "<<++t<<"\nFuse was blown.\n\n";
        } else {
            cout<<"Sequence "<<++t<<"\nFuse was not blown.\nMaximal power consumption was "
                <<max<<" amperes.\n\n";
        }
    }
}
