/*
 * =====================================================================================
 *
 *       Filename:  13052.cpp
 *
 *    Description:  Fisa Flood
 *
 *        Version:  1.0
 *        Created:  08/14/2016 10:47:22
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
#include <vector>
#define N 1001

using namespace std;

int main(){
    int t, a, b,s;
    double p;

    scanf("%d",&t);
    int i = 0;
    while (i++<t){
        scanf("%d%d",&a,&b);
        if (a||b){
            if (b%2) {
                printf("Case %d: 0.000 1.000\n",i);
            } else {
                printf("Case %d: 1.000 0.000\n",i);
            }
        } else {
            printf("Case %d: 0.000 0.000\n",i);
        }
    }
}
