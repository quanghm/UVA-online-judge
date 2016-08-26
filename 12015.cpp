/*
 * =====================================================================================
 *
 *       Filename:  12015.cpp
 *
 *    Description:  Google is felling lucky -- stable sort
 *
 *        Version:  1.0
 *        Created:  08/25/2016 14:47:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> val(10);

bool compare(int i, int j){
    return val[i] > val[j];
}

int main(){
    int t,c=0,temp;

    cin >> t;

    while (c++<t){
        vector<int> index(10);
        vector<string> site(10);
        for (int i = 0; i<10; ++i){
            cin>> site[i] >> val[i];
            index[i] = i;
        }

        stable_sort(index.begin(),index.end(),compare);

        cout<<"Case #"<<c<<":\n";

        temp = val[index[0]];
        for (int i = 0; i<10 && val[index[i]] == temp; ++i){
            cout<<site[index[i]]<<"\n";
        }
    }
}

