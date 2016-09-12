/*
 * =====================================================================================
 *
 *       Filename:  378.cpp
 *
 *    Description:  Intersecting Lines
 *
 *        Version:  1.0
 *        Created:  09/06/2016 23:19:37
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

using namespace std;
void printQuotient(long long a, long long b){
    if (b<0){
        b=-b;
        if (a>0){
            printf("-");
        } else {
            a=-a;
        }
    } else if (a<0){
        printf("-");
        a=-a;
    }

    printf("%lld.",a/b);
    a %=b;
    printf("%02lld", ((a*1000)/b+5)/10 );
}
int main(){
    int numCases;
    
    long long coords[8];

    long long  dx1,dy1,dx2,dy2; // directions
    long long  d,dx,dy,u,v;

    scanf("%d", &numCases);

    printf("INTERSECTING LINES OUTPUT\n");

    while (numCases--){
        // read the coordinates
        for (int i = 0; i<8; i++){
            scanf("%lld", coords+i);
        }

        dx1 = coords[2]-coords[0];
        dy1 = coords[3]-coords[1];

        dx2 = coords[6]-coords[4];
        dy2 = coords[7]-coords[5];

        d= dy2 * dx1 - dy1 * dx2;

        if (d){ // not zero, having a common point
            u = coords[3] * coords[0] - coords[1] * coords[2];
            v = coords[7] * coords[4] - coords[5] * coords[6]; 

            dx = dx1 * v - dx2 * u;
            dy = dy1 * v - dy2 * u;

            printf("POINT ");
            printQuotient(dx,d);
            printf(" ");
            printQuotient(dy,d);
            printf("\n");
            continue;
        }

        // d==0 
        dx2 = coords[6] - coords[0];
        dy2 = coords[7] - coords[1];
        if (dx2*dy1 == dx1*dy2){
            printf("LINE\n");
        } else {
            printf("NONE\n");
        }
    }
    printf("END OF OUTPUT\n");
}
