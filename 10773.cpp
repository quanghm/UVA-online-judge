/*
 * =====================================================================================
 *
 *       Filename:  10773.cpp
 *
 *    Description:  Back to Intermediate Math
 *
 *        Version:  1.0
 *        Created:  08/29/2016 15:24:38
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
    int numCases,c=0;
    double d, v, u;

    scanf("%d",&numCases);

    while (c++<numCases){
        scanf("%lf%lf%lf",&d, &v,&u);
        if (u<=v || v==0){
            printf("Case %d: can\'t determine\n",c);
            continue;
        } 
        printf("Case %d: %.03lf\n", c,d/sqrt(u*u-v*v)-d/u);
    }
}
