/*
 * =====================================================================================
 *
 *       Filename:  1498.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 11:24:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int k,n,m,x,y;
    
    // read number of queries
    while((cin>> k)&&k){
        // read center point
        cin>>n>>m;
        char position;

        while (k--){
            cin >> x >> y;
            if (x==n || y ==m ){
                cout<<"divisa\n";
            }
            else{
                position = ((bool)(x>n)<<1) | (bool)(y>m);
            switch (position) {
                case 0: // x<n and y<m
                    cout<<"SO\n";
                    break;
                case 1: // x<n and y>m
                    cout<<"NO\n";
                    break;
                case 2: // x>n and y<m
                    cout<<"SE\n";
                    break;
                case 3: // x>n and y>n
                    cout<<"NE\n";
                    break;
                }
            }
        }
    }
}
