/*
 * =====================================================================================
 *
 *       Filename:  12850.cpp
 *
 *    Description:  Skating Puzzle
 *
 *        Version:  1.0
 *        Created:  08/19/2016 07:41:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main(){
    int n,c=0;

    int r1,r2, t1,t2;
    int tj1, tj2, tm1, tm2;

    scanf("%d",&n);

    while (c++<n){
        scanf("%d.%d%d.%d",&r1,&r2,&t1,&t2);

//        printf("%d.%d %d.%d\n",r1,r2,t1,t2);
        
        t1 = t1 * 100 + t2;
        r1 = r1 * 100 + r2 - 100;

        // tm = tj + t1, tm = tj*r1;
        // t1 = (r1-1)* tj;
        // tj = t1/(r1-1);
        tj1 = t1 / r1; // integer part
        tj2 = ((t1%r1) * 10000  / r1 + 5)/10;
        
        t1 *= 10; 
        t1 += tj1*1000 + tj2;

        tm1 = t1 / 1000;
        tm2 = t1 % 1000;
        printf("Case %d: %d.%03d %d.%03d\n",c,tj1,tj2,tm1,tm2);

    }
}
