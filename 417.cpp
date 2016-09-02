/*
 * =====================================================================================
 *
 *       Filename:  417.cpp
 *
 *    Description:  Word index
 *
 *        Version:  1.0
 *        Created:  08/31/2016 10:07:55
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
#include <cstdio>
using namespace std;

int numWord[6][27]={}; // numWord[length][numChar];

int getIndex(string &word){
    int length = word.length();
    if (length==1) return (word[0]-'a'+1);

    char ch='a'-1;

    int sum=0;
    for (string::iterator it = word.begin();
            it != word.end(); ++it){
        if (*it <=ch) return 0;
        
        length --;

        sum+=numWord[length][26];

        for (char i = ch+1; i< *it; ++i){
            sum += numWord[length]['z'-i];
        }

        ch=*it;
    }
    return sum;
}
int main(){
    string word;
    char ch;
    int length, sum;


    for (int j = 0; j<27; j++){
        numWord[0][j] = 1;
    }

    for (int length = 1; length<5; length++){
        for (int numChar = length; numChar<27; numChar++){
            numWord[length][numChar] = numWord[length][numChar-1] + numWord[length-1][numChar-1];
        }
    }

    while (cin>>word){
        cout<<getIndex(word)<<"\n";
    }
}
