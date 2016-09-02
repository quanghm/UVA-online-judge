/*
 * =====================================================================================
 *
 *       Filename:  455.cpp
 *
 *    Description:  Periodic Strings
 *
 *        Version:  1.0
 *        Created:  09/02/2016 16:35:41
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
#include <vector>

using namespace std;

int main(){
    string line;
    int numCase, period, head, tail,length;

    cin>> numCase;

    for (;;){
        cin>> line;

        length = line.length();
        vector<int> divisors;
        for (int i =1; i<=length;i++){
            if (length % i == 0) divisors.push_back(i);
        }
        vector<int>::iterator it;
        for ( it= divisors.begin();it!=divisors.end()-1;){
            for (head=0,tail=*it; head<=length; ++head, (tail==length-1)?(tail=0):(tail++)){
                if (line[head] != line[tail]) break;
            }
            if (head<length) {it++;} else{break;}
        }
        cout<<*it<<"\n";
        if (--numCase) {cout<<"\n";} else break;
    }
}
