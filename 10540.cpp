/*
 * =====================================================================================
 *
 *       Filename:  10540.cpp
 *
 *    Description:  Flowers of a Beautiful Mind
 *
 *        Version:  1.0
 *        Created:  08/29/2016 16:42:27
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

const double pi = 2 * acos(0.0);

int main(){
    int r,n,half, c=1;

    double alpha, total1, total2,total;

    while (scanf("%d %d",&r, &n) && r){
        total1=0,total2=0, half = (n-1)/2;
        printf("Set %d:\n%d\n",c++,half+1);
        
        // r now is the area of n circles
        r = n*r*r;

        for (int i = half; i;--i){
            alpha = (1 - double(2.0*i)/n)*pi;
            total = r * (alpha - sin(alpha) );
            printf("%.04lf %.04lf\n", total, total + total2 - 2*total1);

            total2=total1, total1=total;
        }
        total = r*pi;
        printf("%.04lf %.04lf\n", total, total + total2 - 2*total1);

    }
}
