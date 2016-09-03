/*
 * =====================================================================================
 *
 *       Filename:  10361.cpp
 *
 *    Description:  Automatic Poetry
 *
 *        Version:  1.0
 *        Created:  09/02/2016 17:30:56
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
    int n;
    string line,s2,s3,s4,s5;
    string::iterator it;
    bool isS2;

    cin>>n; getline(cin,line);
    while (n--){
        getline(cin,line);
        for (it = line.begin(); *it!='<'; it++){
            cout<<*it;
        }
        s2.clear(); it++;
        while (*it!='>'){
            s2 += *it;
            cout<<*it;
            it++;
        }
        it++;
        s3.clear();
        while (*it!='<'){
            s3 += *it;
            cout<<*it;
            it++;
        }
        it++;
        s4.clear();
        while (*it!='>'){
            s4 += *it;
            cout<<*it;
            it++;
        }
        it++;
        s5.clear();
        while (it!=line.end()){
            s5 += *it;
            cout<<*it;
            it++;
        }

//        it++;
//        while (it!=line.end()){
//            cout<<*it;
//            it++;
//        }
        cout<<"\n";

        getline(cin,line);
        
        line.erase(line.end()-3,line.end());
        cout<<line<<s4<<s3<<s2<<s5<<"\n";
    }
    
}
