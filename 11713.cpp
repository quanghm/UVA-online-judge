/*
 * =====================================================================================
 *
 *       Filename:  11713.cpp
 *
 *    Description:  Abstract Name
 *
 *        Version:  1.0
 *        Created:  09/13/2016 10:54:17
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
#include <iostream>

using namespace std;

int main(){
    int n,l,i;
    string s1, s2;
    bool isVowel[128]={};
    isVowel['a']=1;
    isVowel['e']=1;
    isVowel['i']=1;
    isVowel['o']=1;
    isVowel['u']=1;

    cin>>n;

    while (n--){
        cin>>s1>>s2;

        l=s1.length();
        if (l!=s2.length()){
            cout<<"No\n";
            continue;
        }

        for (i=0; i<l; i++){
            if ((isVowel[s1[i]] && isVowel[s2[i]])||
                   s1[i]==s2[i]) {
                continue;
            } else {
                break;
            }
        }
        (i<l)?(cout<<"No\n"):(cout<<"Yes\n");
    }
}
