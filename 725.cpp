/*
 * =====================================================================================
 *
 *       Filename:  725.cpp
 *
 *    Description:  Division
 *
 *        Version:  1.0
 *        Created:  09/10/2016 06:36:02
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
#include <vector>
#include <algorithm>

#define max 30240

using namespace std;

bool test(int s,vector<int>digits){
    digits.resize(10);
    for (int i = 5; i<10;++i){
        digits[i] = s % 10;
        s /= 10;
    }
    sort(digits.begin(),digits.end());
    for (int i=0;i<9;i++){
        if (digits[i]==digits[i+1]) return false;
    }

    return true;
}
int main(){
    int n;
    int candidate[max];
    bool isFound=0,isFirst=1,result;
    bool isUsed[10]={0};
    vector<int>digits(5);

    int s1,s2,s3,s4;
    // generate candidate
    n=0;
    for (int i1=1; i1<10; i1++){
        isUsed[i1]=1;
        for (int i2=1;i2<10;i2++){
            if (isUsed[i2]) continue;
            isUsed[i2]=1;
            s1=10*i1+i2;
            for (int i3=1;i3<10;i3++){
                if (isUsed[i3]) continue;
                isUsed[i3]=1;
                s2 = s1*10+i3;
                for (int i4=1;i4<10;i4++){
                    if (isUsed[i4]) continue;
                    candidate[n++]=s2*10+i4;
                }
                isUsed[i3]=0;
            }
            isUsed[i2]=0;
        }
        isUsed[i1]=0;
    }
    
    for (int i1=1; i1<10; i1++){
        isUsed[i1]=1;
        for (int i2=0;i2<10;i2++){
            if (isUsed[i2]) continue;
            isUsed[i2]=1;
            s1=10*i1+i2;
            for (int i3=0;i3<10;i3++){
                if (isUsed[i3]) continue;
                isUsed[i3]=1;
                s2 = s1*10+i3;
                for (int i4=0;i4<10;i4++){
                    if (isUsed[i4]) continue;
                    isUsed[i4]=1; 
                    s3 = s2*10 + i4;
                    for (int i5=0;i5<10;i5++){
                        if (isUsed[i5]) continue;
                        candidate[n++] = s3*10+i5;
                    }
                    isUsed[i4]=0;
                }
                isUsed[i3]=0;
            }
            isUsed[i2]=0;
        }
        isUsed[i1]=0;
    }
    // done getting list of candidates;

    while (scanf("%d",&n)&&n){
        (isFirst)? (isFirst=0):(printf("\n"));
        isFound=0;
        

        for (int i=0; i<max; i++){
            s2=candidate[i];
            for (int ii=0;ii<5;ii++){
                digits[ii]= s2 %10;
                s2 /= 10;
            }
            s1 = candidate[i]*n;
            if (s1<12345) continue;
            if (s1>98765) break;
            
            result = test(s1,digits);
            if (result){
                isFound=1;
                printf("%05d / %05d = %d\n",s1,candidate[i],n);
            }
        }
        if (!isFound) 
            printf("There are no solutions for %d.\n",n);
    }

}
