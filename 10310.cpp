/*
 * =====================================================================================
 *
 *       Filename:  10310.cpp
 *
 *    Description:  Dog and Gopher -- floating point error
 *
 *        Version:  1.0
 *        Created:  09/11/2016 22:12:02
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
long long getVal(){
    char ch=0;
    int buff1=0, buff2=0,sign=1;

    ch=getchar();
    if (ch=='-'){
        sign=-1;
        ch=getchar();
    }
    while (ch!=' ' && ch!='\n' && ch!='.'){
        buff1 = buff1*10+ch-'0';
        ch=getchar();
    }

    if (ch=='.'){
        ch=getchar();
        buff2 = 0;
        while (ch!=' '&&ch!='\n'){
            buff1 = buff1*10+ch-'0';
            buff2++;
            ch=getchar();
        }
        switch (buff2){
            case 0:
                buff1*=1000;
                break;
            case 1:
                buff1*=100;
                break;
            case 2:
                buff1*=10;
                break;
        }
    } else {
        buff1*=1000;
    }
    return buff1*sign;
}
void print(long long &num){
    if (num==0){
        printf("0.000");
        return;
    }
    if (num<0){
        printf("-");
        num=-num;
    }
    printf("%lld.%03lld",num/1000,num%1000);
}
int main(){
    int numHoles;
    long long  dg[4]; // coordinates of dogs and Gopher
    long long xc,yc, rSquare,distSquare;
    double buff1, buff2;
    bool isFound;

    while (scanf("%d",&numHoles)!=EOF){
        getchar(); // trailing char
        // dogs coord
        for (int i=0; i<4; i++){
            dg[i] = getVal();
        }
        // from now on, everything is scaled by 3
        // center of circle
        xc = dg[0] * 4 - dg[2];
        yc = dg[1] * 4 - dg[3];

        // radius
        rSquare = 4*( (dg[0]-dg[2])*(dg[0]-dg[2]) +
                   (dg[1]-dg[3])*(dg[1]-dg[3]) );

        isFound = false;
        while (numHoles--){
            for (int i=0;i<2;i++){
                dg[i] = 3*getVal();
            }

            if (isFound) continue;

            distSquare = (dg[0]-xc)*(dg[0]-xc) +
                         (dg[1]-yc)*(dg[1]-yc);
            if (distSquare<=rSquare){
                isFound=true;
                // save coords
                dg[2]=dg[0]/3; 
                dg[3]=dg[1]/3;
            }
        }

        if (isFound){
            printf("The gopher can escape through the hole at (");
            print(dg[2]);
            printf(",");
            print(dg[3]);
            printf(").\n");
        } else {
            printf("The gopher cannot escape.\n");
        }

    }
}
