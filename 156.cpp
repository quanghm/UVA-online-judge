/*
 * =====================================================================================
 *
 *       Filename:  156.cpp
 *
 *    Description:  Anagrams 
 *
 *        Version:  1.0
 *        Created:  08/29/2016 00:07:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

void toLowerCase(string &line){
    for (string::iterator it = line.begin();
            it != line.end(); ++it){
        if ('A'<= *it && *it <= 'Z'){
            *it += 32;
        }
    }
}

int main(){
    vector<string> dict;
    vector<string> sortedDict;
    map<string,int> counts;

    string line;

    int numWords;

    for (;;){
        cin >> line;
        if (line[0] == '#') break;

        dict.push_back(line);
        // convert to lower case and sort
        toLowerCase(line);
        sort(line.begin(),line.end());

        sortedDict.push_back(line);
        // increase map:
        counts[line]++;
    }

    numWords = dict.size();
    vector<string> anagrams;

    for (int i = 0 ; i< numWords; ++i){
        if (counts[sortedDict[i]]==1){
            anagrams.push_back(dict[i]);
        }
    }
    sort(anagrams.begin(),anagrams.end());
    for (vector<string>::iterator it = anagrams.begin(); 
            it != anagrams.end(); ++it){
        cout<< (*it)<<"\n";
    }
}
