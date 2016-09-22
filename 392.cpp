/*
 * =====================================================================================
 *
 *       Filename:  392.cpp
 *
 *    Description:  Polynomial Showdown
 *
 *        Version:  1.0
 *        Created:  09/13/2016 22:06:28
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
    int coeff[9];
    while (cin>>coeff[8]){
        int deg=0,c=8;
        while (c){
            if (coeff[c]&&!deg) deg=c;
            cin>>coeff[--c];
        }

        if (deg==0){
            cout<<coeff[0]<<"\n";
            continue;
        }

        switch (coeff[deg]){
            case 1:
                break;
            case -1:
                cout<<"-";
                break;
            default:
                cout<<coeff[deg];
                break;
        }
        (deg==1)?(cout<<"x"):(cout<<"x^"<<deg);
        while (deg--){
            if (!coeff[deg]){
                continue;
            } else if (coeff[deg]<0){
                cout<<" - ";
                coeff[deg]*=-1;
            } else {
                cout<<" + ";
            }
            if (coeff[deg]!=1|| !deg) cout<<coeff[deg];
            if (deg>1){
                cout<<"x^"<<deg;
            } else if (deg==1){
                cout<<"x";
            }
        }
        cout<<"\n";
    }
}
