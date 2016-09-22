/*
 * =====================================================================================
 *
 *       Filename:  10077.cpp
 *
 *    Description:  The Stern-Brocot Number System
 *
 *        Version:  1.0
 *        Created:  09/12/2016 19:50:29
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
    int m, n, temp,ratio;
    bool isRight;

    while (cin>>m>>n && (m!=1|| n!=1) ){
        isRight=1;

        for (;;){
            temp = m%n;
            ratio = m/n;
            if (temp){
                if (isRight){
                    while (ratio--){
                        cout<<"R";
                    }
                } else {
                    while (ratio--){
                        cout<<"L";
                    }
                }
                m = n, n=temp;
                isRight = !isRight;
            } else {
                if (isRight){
                    while (--ratio){
                        cout<<"R";
                    }
                } else {
                    while (--ratio){
                        cout<<"L";
                    }
                }
                break;
            }
        }
        cout<<"\n";
    }
}
