/*
 * =====================================================================================
 *
 *       Filename:  13055.cpp
 *
 *    Description:  Inception
 *
 *        Version:  1.0
 *        Created:  08/29/2016 15:51:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<string>
#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;

    stack<string> names;

    cin>>n;
    string query;

    while (n--){
        cin>> query;
        switch(query[0]){
            case 'S': // sleep
                cin>> query;
                names.push(query);
                break;
            case 'K': // kick
                if (!names.empty()){
                    names.pop();
                }
                break;
            case 'T':
                if (names.empty()){
                    cout<<"Not in a dream\n";
                } else {
                    cout<<names.top()<<"\n";
                }
        }
    }
}
