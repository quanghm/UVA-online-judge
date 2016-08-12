/*
 * =====================================================================================
 *
 *       Filename:  12289.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 12:45:24
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

using namespace std;

int main(){
    int n;
    string num;

    cin>>n;
    getline(cin,num);

    while (n--){
        getline(cin,num);
        if (num.length()==5){
            cout<<"3\n";
        } else {
            int r = (int)(num[0]!='t')+(int)(num[1]!='w')+(int)(num[2]!='o');
            if (r < 2){
                cout<<"2\n";
            } else {
                cout<<"1\n";
            }
        }
    }
}
