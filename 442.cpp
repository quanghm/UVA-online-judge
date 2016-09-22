/*
 * =====================================================================================
 *
 *       Filename:  442.cpp
 *
 *    Description:  Matrix Chain Multiplication
 *
 *        Version:  1.0
 *        Created:  09/13/2016 09:46:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main(){
    char ch;
    int row, col;

    int rows[97];
    int cols[97];

    int numMatrix;
    long long sum;
    string line;

    pair<int,int> size1,size2;

    cin>>numMatrix;
    while (numMatrix--){
        cin>> ch;
        cin>>rows[ch]>>cols[ch];
    }
    getline(cin,line);

    while (getline(cin,line)){
        sum=0;
        stack<pair<int, int> > expression;
        
        for (string::iterator it = line.begin();
                it!=line.end()&&sum>=0; ++it){
            switch (*it){
                case '(':
                    break;
                case ')':
                    size1 = expression.top();
                    expression.pop();
                    size2 = expression.top();
                    expression.pop();
                    if (size1.first == size2.second){
                        sum += size1.first * size2.first *
                               size1.second;
                        expression.push(pair<int,int>(size2.first, size1.second));
                    } else {
                        sum=-1;
                    }
                    break;
                default:
                    expression.push(pair<int,int>(rows[*it],cols[*it]));
                    break;
            }
        }
        (sum>=0)?(cout<<sum<<"\n"):(cout<<"error\n");

    }
}
