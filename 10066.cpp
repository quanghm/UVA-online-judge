/*
 * =====================================================================================
 *
 *       Filename:  10066.cpp
 *
 *    Description:  longest common subsequence
 *
 *        Version:  1.0
 *        Created:  08/04/2016 15:30:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int n1, n2,c=1;

    int t1[101],t2[101];
    char common[101][101];
    common[0][0]=0;
    for (int i =1;i<102;++i){
        common[0][i]=0;
        common[i][0]=0;
    }

    while (scanf("%d %d", &n1, &n2) && (n1) ){
        
        // result 
        char r = 0,maxCommon;

        // read first sequence
        for (int i = 1; i<=n1; ++i){
            scanf("%d", t1+i);
        }

        // read the second sequence
        for (int i = 1; i<=n2; ++i){
            scanf("%d",t2+i);
        }

        for (int i1 = 1; i1<=n1; ++i1){
            for (int i2 = 1; i2<=n2; ++i2){
                // max in the case the two current numbers are not equal
                maxCommon = (common[i1-1][i2]>common[i1][i2-1])? common[i1-1][i2]:common[i1][i2-1];
                
                if (t1[i1]==t2[i2]){
                    common[i1][i2] = (maxCommon > common[i1-1][i2-1]) ? maxCommon : (common[i1-1][i2-1]+1);
                } else {
                    common[i1][i2] = maxCommon;
                }

                if (common[i1][i2]>r) r=common[i1][i2];
            }
        }

        // print result
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",c++,r);
    }
}
