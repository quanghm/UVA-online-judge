/*
 * =====================================================================================
 *
 *       Filename:  1585.cpp
 *
 *    Description:  Score
 *
 *        Version:  1.0
 *        Created:  08/24/2016 14:51:03
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
    char ch;
    long long sum, sequence;
    
    int numCases;

    scanf("%d",&numCases);
    getchar();

    while (numCases--){
        sum = 0;
        for (;;){
            ch = 'X';
            while (ch=='X'){
                ch=getchar();
            }

            sequence=0;
            while (ch=='O'){
                sequence++;
                ch=getchar();
                sum += sequence;
            }
            if (ch=='\n'||ch==EOF) break;
        }
        
        printf("%lld\n",sum);
    }
}
