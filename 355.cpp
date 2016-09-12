/*
 * =====================================================================================
 *
 *       Filename:  355.cpp
 *
 *    Description:  The Bases are Loaded
 *
 *        Version:  1.0
 *        Created:  09/07/2016 06:08:35
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
            cout<<num<<" is an illegal base "<<fromBase<<
                " number\n";
            return;
        }
        value = value*fromBase + digit;
    }

    numDigits = 0; // now digit is number of digits
    char newNum[40];
    if (value==0){
        cout<< num<<" base "<<fromBase<< " = 0 base "<<
            toBase<<"\n";
        return;
    }

    while (value){
        digit = value % toBase;
        newNum[numDigits++] = (digit>9)?(digit+55):(digit+48);

        value /= toBase;
    }

    // print:
    cout<< num << " base "<< fromBase<< " = ";
    while (numDigits--){
        cout<<newNum[numDigits];
    }
    cout<<" base "<< toBase<<"\n";

}

int main(){
    string num;
    int fromBase, toBase;

    while (cin>>fromBase>>toBase>>num){
        convertBase(num,fromBase,toBase);
    }
}
