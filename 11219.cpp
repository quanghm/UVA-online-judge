/*
 * =====================================================================================
 *
 *       Filename:  11219.cpp
 *
 *    Description:  How old are you?
 *
 *        Version:  1.0
 *        Created:  09/08/2016 22:48:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <cstdio>

using namespace std;

int d1,m1,y1,d2,m2,y2;

void check(){
    if (y1 < y2) {y1=-1;return;}

    if (y1==y2){
        if (m1<m2 || (m1==m2 && d1<d2) ) {y1=-1;}
        else {y1=0;}
        return;
    }
    
    // y1 > y2
    y1-=y2;
    if (m1<m2 || (m1 == m2 && d1<d2) ){
        y1 -= 1;
    }
}

int main(){
    int n, c=0;
    scanf("%d",&n);
    string line;

    while (c++<n){
//        cin >> line;
//        d1 = line[0] * 10 + line[1] - 528;
//        m1 = line[3] * 10 + line[4] - 528;
//        y1 = line[6] * 1000 + line[7] * 100 + line[8] * 10 +
//             line[9] - 48 *1111;
//
//        cin >> line;
//        d2 = line[0] * 10 + line[1] - 528;
//        m2 = line[3] * 10 + line[4] - 528;
//        y2 = line[6] * 1000 + line[7] * 100 + line[8] * 10 +
//             line[9] - 48 *1111;
        scanf("%d/%d/%d",&d1,&m1,&y1);
        scanf("%d/%d/%d",&d2,&m2,&y2);
        check();
        printf("Case #%d: ",c);
        if (y1==-1){
            printf("Invalid birth date\n");
        } else if (y1>130){
            printf("Check birth date\n");
        } else {
            printf("%d\n",y1);
        }

    }
}
