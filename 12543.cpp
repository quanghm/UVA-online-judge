/*
 * =====================================================================================
 *
 *       Filename:  12543.cpp
 *
 *    Description:  Longest Word
 *
 *        Version:  1.0
 *        Created:  08/23/2016 00:04:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;
bool isChar(char ch){
    return (ch<='z' && ch>='a') || 
        (ch>='A' && ch<='Z') || 
        (ch=='-');
}
int main(){
    string longest, temp;
    char ch=1;
    int max = 0;
    bool isNotEnd=1;

    for (;isNotEnd;){
        for (;;){
            ch = getchar();
            if (isChar(ch))
                break;
        }
        
        temp = "";
        
        for (;;){
            temp.push_back(ch);
            ch=getchar();
            if (!isChar(ch)){
                break;
            }
        }
        
        
        isNotEnd=(temp.compare("E-N-D")!=0);

        if (max<temp.length()) {
            max = temp.length();
            longest.swap(temp);
        }
    }

    for (string::iterator it = longest.begin();it!=longest.end();
            ++it){
        putchar(tolower(*it));
    }
    printf("\n");
}
