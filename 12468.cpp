/*
 * =====================================================================================
 *
 *       Filename:  12468.cpp
 *
 *    Description:  Zapping
 *
 *        Version:  1.0
 *        Created:  09/01/2016 11:25:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
    int a, b;
    while (cin>> a >> b && a>-1){
        a = (a>b) ? (a-b) : (b-a);
        (a>50) ?  (cout<< 100 - a <<"\n") : (cout<< a<< "\n");
    }
}
