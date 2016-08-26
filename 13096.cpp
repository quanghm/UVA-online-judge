/*
 * =====================================================================================
 *
 *       Filename:  13096.cpp
 *
 *    Description:  Standard Deviation 2
 *
 *        Version:  1.0
 *        Created:  08/23/2016 11:37:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<cmath>
#include<cstdio>

using namespace std;

int main(){
    long long  n;
    while (scanf("%lld",&n) && n){
        printf("%.06lf\n", sqrt( ( (double)( n*(n+1) ) )/3));
    }
}
