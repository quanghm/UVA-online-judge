/*
 * =====================================================================================
 *
 *       Filename:  11909.cpp
 *
 *    Description:  Soya Milk
 *
 *        Version:  1.0
 *        Created:  09/22/2016 22:32:55
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
#include <cmath>

using namespace std;

const double piPerDeg=acos(0)/90;

int main(){
    double tg[90]={};
    double ans,tmp;
    int l,w,h,theta;

    for (int i=0; i<90;i++){
        tg[i] = tan(i*piPerDeg);
    }

    while (scanf("%d %d %d %d", &l, &w, &h, &theta)!=EOF){
        tmp = l*tg[theta];
        if (h>tmp){
            ans = ((double)(l*w))*(h-tmp/2);
        } else {
            ans = tg[90-theta] * h * h * w/2;
        }
        printf("%.03lf mL\n",ans);
    }
}
