/*
 * =====================================================================================
 *
 *       Filename:  441.cpp
 *
 *    Description:  Lotto
 *
 *        Version:  1.0
 *        Created:  08/15/2016 09:04:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int s[12];
    int k;


    bool isFirst=1;


    while (cin>> k && k){
        if (isFirst){
            isFirst=false;
        } else{
            printf("\n");
        }

        for (int i=0;i<k;++i){
            cin>>s[i];
        }
        
        for (int i1 = 0; i1<k-5; i1++){
            for (int i2 = i1+1; i2<k-4; i2++){
                for (int i3 = i2+1; i3<k-3; i3++){
                    for (int i4=i3+1;i4<k-2;i4++){
                        for (int i5=i4+1;i5<k-1;i5++){
                            for (int i6=i5+1;i6<k;i6++){
                                printf("%d %d %d %d %d %d\n",
                                        s[i1],s[i2],s[i3],
                                        s[i4],s[i5],s[i6]);
                            }
                        }
                    }
                }
            }
        }
    }
}
