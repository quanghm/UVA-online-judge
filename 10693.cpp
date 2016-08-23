/*
 * =====================================================================================
 *
 *       Filename:  10693.cpp
 *
 *    Description:  Traffic Volume
 *
 *        Version:  1.0
 *        Created:  08/17/2016 09:50:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    double d, v, s=sqrt(2);
    int l, f;
    while (scanf("%d%d",&l,&f) && l){
        v = s*sqrt(l*f);

        d = 1800*v/l;
        printf("%.08lf %.08lf\n", v,d);
    }
}
