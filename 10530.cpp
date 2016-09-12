/*
 * =====================================================================================
 *
 *       Filename:  10530.cpp
 *
 *    Description:  Guessing Game
 *
 *        Version:  1.0
 *        Created:  09/08/2016 23:38:09
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

int main(){
    string guess;
    int min, max, temp=1;

    for(;;){
        min = 0, max =11;
        guess="a";
        for (;;){
            cin>>temp;
            if (!temp) return 0;

            cin >> guess; cin>> guess;
            if (guess[0]=='h'){
                    if (max>temp) max=temp;
            } else if (guess[0] == 'l'){
                if (min<temp) min=temp;
            } else {
                if (min<temp && temp<max){
                    cout<<"Stan may be honest\n";
                } else {
                    cout<<"Stan is dishonest\n";
                }
                break;
            }
        }
    }
}
