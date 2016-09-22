/*
 * =====================================================================================
 *
 *       Filename:  10192.cpp
 *
 *    Description:  Vacation -- longest common subsequence
 *
 *        Version:  1.0
 *        Created:  08/30/2016 13:55:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1, s2;
    int l1, l2, temp;
    int c=0;
    for(;;){
        getline(cin,s1);
        if (s1[0]=='#') break;
        getline(cin,s2);
        l1 = s1.length(), l2 = s2.length();
        int common[101][101]={};

        for (int r = 1; r<=l1; r++){
            for (int c=1; c<=l2; c++){
                temp = (common[r-1][c]>common[r][c-1])?
                        common[r-1][c] : common[r][c-1];

                if (s1[r-1]==s2[c-1]){
                    common[r][c] = (temp>common[r-1][c-1])?
                                    temp: (common[r-1][c-1]+1);
                } else {
                    common[r][c] = temp;
                }
            }
        }
        cout<< "Case #"<<++c<<": you can visit at most "<<
            common[l1][l2]<<" cities.\n";
    }
}
