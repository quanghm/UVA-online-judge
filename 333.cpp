/*
 * =====================================================================================
 *
 *       Filename:  333.cpp
 *
 *    Description:  Recognizing Good ISBNs
 *
 *        Version:  1.0
 *        Created:  09/17/2016 14:47:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void validateISBN(string &line);

int main(){
    string line;

    while (getline(cin,line)){
        validateISBN(line);
    }
}

void validateISBN(string &line){
    int start=0, end=line.length()-1;
    while (line[start]==' ') start++;
    while (end && line[end]==' ') end--;

    if (start>end) {
        cout<<" is incorrect.\n";
        return;
    }

    // string starts from -start- to -end-
    int s=0, // validating sum
        i=10; // digit order
    for (int ii=start; ii<=end; ii++) cout<<line[ii];
    for (int ii=start; ii<=end; ii++){
        switch (line[ii]){
            case ' ':
            case '-':
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                s += (line[ii]-'0') * (i--);
                break;
            case 'X':
                if (i==1){s += 10*(i--);}
                else { cout<<" is incorrect.\n"; return;}
                break;
            default:
                cout<<" is incorrect.\n";
                return;
                break;
        }
    }

    if (i || (s%11)) {
        cout<<" is incorrect.\n";
    } else {
        cout<<" is correct.\n";
    }
}
