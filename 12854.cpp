/*
 * =====================================================================================
 *
 *       Filename:  12854.cpp
 *
 *    Description:  Automated Checking Machine
 *
 *        Version:  1.0
 *        Created:  08/23/2016 02:35:43
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

using namespace std;

int main(){
    char first[5]={};
    char ch;
    bool r;

    while (cin>>first[0]){
        for (int i=1;i<5;i++){
            cin>>first[i];
        }

        r = true;
        for (int i=0;i<5;i++){
            cin>>ch;
            r = r && (ch!=first[i]);
        }

        if (r) {
            cout<<"Y\n";
        } else {
            cout<<"N\n";
        }
    }
}
