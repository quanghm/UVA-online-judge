/*
 * =====================================================================================
 *
 *       Filename:  834.cpp
 *
 *    Description:  Continue Fractions
 *
 *        Version:  1.0
 *        Created:  08/29/2016 11:41:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a,b,size;
    while (cin>> a>> b){
        if (b==0) { cout<<"[]\n"; continue;}
        vector<int> v;

        
        for (;;){
            size= a/b;
            v.push_back(size);

            size = a % b;
            if (size ==0){
                break;
            } else {
                a = b, b= size;
            }
        }
        size = v.size();
        switch(size){
            case 0:
                cout<<"[]\n";
                break;
            case 1:
                cout<<"["<<v[0]<<"]\n";
                break;
            default:
                cout<<"["<<v[0]<<";";
                size--;
                for (int i = 1;i<size; i++){
                    cout<<v[i]<<",";
                }
                cout<<v[size]<<"]\n";
        }
    }
}
