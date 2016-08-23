/*
 * =====================================================================================
 *
 *       Filename:  537.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2016 22:16:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int numCases;
    char ch=0, buff1,buff2;
    double val1,val2; // store values 

    scanf("%d", &numCases);

    while (ch!='\n'){
        ch=getchar();
    }

    int i=0;

    while (i++<numCases){
        // read char until first '=' sign
        while (ch!='='){
            buff1 = ch;
            ch = getchar();
        }
        // now read the first value
        scanf("%lf",&val1);
        ch=getchar();
        
        switch (ch){
            case 'm':
                val1 /=1000;
                break;
            case 'k':
                val1 *=1000;
                break;
            case 'M':
                val1 *= 1e6;
                break;
        }

        // read until second '=' sign
        while (ch!='='){
            buff2=ch;
            ch=getchar();
        }

        // read the second value
        scanf("%lf", &val2);
        
        // read the 2nd prefix, if any
        ch=getchar();
        switch (ch){
            case 'm':
                val2 /=1000;
                break;
            case 'k':
                val2 *=1000;
                break;
            case 'M':
                val2 *= 1e6;
                break;
        }


        printf("Problem #%d\n",i);
        // Let us classify the problem:
        if (buff1=='P'){
            if (buff2 =='U'){
                printf("I=%.02lfA\n\n",val1/val2);
            } else {
                printf("U=%.02lfV\n\n",val1/val2);
            }
        } else if (buff1=='U'){
            if (buff2 == 'P'){
                printf("I=%.02lfA\n\n",val2/val1);
            } else{
                printf("P=%.02lfW\n\n",val1*val2);
            }
        } else { // buff1 ='I'
            if (buff2=='U'){
                printf("P=%.02lfW\n\n",val1*val2);
            } else {
                printf("U=%.02lfV\n\n",val2/val1);
            }
        }
    }
}

