/*
 * =====================================================================================
 *
 *       Filename:  10282.cpp
 *
 *    Description:  Babel fish
 *
 *        Version:  1.0
 *        Created:  09/01/2016 10:22:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<string, string> dict;
    string line, word;
    int i;

    for (;;) {
        getline(cin,line);
        if (!(line.length())) break;

        i = 0;
        while (line[i] != ' '){
            i++;
        }

        dict[line.substr(i+1)] = line.substr(0,i);
    }

    while (cin>>line){
        word = dict[line];
        if (word.length()){
            cout<<word<<"\n";
        } else{
            cout<<"eh\n";
        }
    }
}
