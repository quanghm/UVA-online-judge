/*
 * =====================================================================================
 *
 *       Filename:  11236.cpp
 *
 *    Description:  Grocery Store
 *
 *        Version:  1.0
 *        Created:  08/10/2016 14:27:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>

using namespace std;

int main(){
    long long s, a, b, c, d;

    for (s = 644; s<=2000; s++){
        for (a = 1; a<=125; a++){
            for (b= a; b<=s/3 && b< 593; b++){
                for ( c = b , d=s; c<= d && c<884; c++){
                    d = s-a-b-c;
//                    if (d<c) break;
                    if ( s*1e6 == a*b*c*d )
                            printf("%lld %lld %lld %lld\n",
                                    a,b,c,d);
                }
            }
        }
    }
}
