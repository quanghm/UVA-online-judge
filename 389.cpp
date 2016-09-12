/*
 * =====================================================================================
 *
 *       Filename:  389.cpp
 *
 *    Description:  Basically Speaking
 *
 *        Version:  1.0
 *        Created:  09/11/2016 08:11:56
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

using namespace std;

void convertBase(string &num, int fromBase, int toBase){

    long long value = 0;
    int digit,numDigits;

    for (string::iterator it = num.begin();
            it!=num.end(); it++){
        digit = (*it>64)?(*it - 55):(*it-48);
        if (digit>=fromBase){
            cout<<"  ERROR\n";
            return;
        }
        value = value*fromBase + digit;
    }

    numDigits = 0; // now digit is number of digits
    char newNum[40];
    if (value==0){
        cout<<"      0\n";
        return;
    }

    while (value){
        digit = value % toBase;
        newNum[numDigits++] = (digit>9)?(digit+55):(digit+48);

        value /= toBase;
    }

    // print:
    if (numDigits>7) {
        cout<<"  ERROR\n";
    } else {
        for (int i=7; i>numDigits; --i){
            cout<<" ";
        }
        while (numDigits--){
            cout<<newNum[numDigits];
        }
        cout<<"\n";
    }
}

int main(){
    string num;
    int
        fromBase,
        toBase;

    while
        (cin>>num>>fromBase>>toBase){
            convertBase(num,fromBase,toBase);
        }
}
