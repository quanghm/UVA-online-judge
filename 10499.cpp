/*
 * =====================================================================================
 *
 *       Filename:  10499.cpp
 *
 *    Description:  The Land of Justice
 *
 *        Version:  1.0
 *        Created:  08/15/2016 15:41:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>

int main(){
    long long n;

    while (scanf("%lld", &n) && n>0){
        if (n==1){
            printf("0%%\n");
        } else {
            n*=25;
            printf("%lld%%\n", n);
        }
    }

}
