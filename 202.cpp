/*
 * =====================================================================================
 *
 *       Filename:  202.cpp
 *
 *    Description:  Repeating Decimals
 *
 *        Version:  1.0
 *        Created:  08/11/2016 15:51:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n,d;                                    // numerator and denominator
    int f,r;                                    // fraction and remainder

    while (scanf("%d %d",&n,&d)!=EOF){
        // print integer part
        f = n/d;
        printf("%d/%d = %d.",n,d,f);
        n%=d;
        int length=1;
        
        vector<int> firstOccurance(d,0);        // if the remainder has occured
        vector<int> digits;                     // digits in order

        while (! firstOccurance[n]){
            firstOccurance[n]=length++;
            n *= 10;
            f = n/d, digits.push_back(f);
            n %= d;
        }

        if (length<=50){
            length -= firstOccurance[n];
            d=0;

            f=firstOccurance[n]-1;
            // print digits before loop
            for (;d<f;++d){
                printf("%d",digits[d]);
            }
            
            // print loop
            printf("(");
            for (int i=0; i<length;++d,++i){
                printf("%d",digits[d]);
            }
            printf(")\n   %d = number of digits in repeating cycle\n\n",length);
        } else{
            length -= firstOccurance[n];
            d=0;
            f=firstOccurance[n]-1;

            // print digist before loop
            for (;d<f;++d){
                printf("%d",digits[d]);
            }

            // print loop
            printf("(");
            for (;d<50;++d){
                printf("%d",digits[d]);
            }
            printf("...)\n   %d = number of digits in repeating cycle\n\n",length);
        } 
    }
}
