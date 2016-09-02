/*
 * =====================================================================================
 *
 *       Filename:  12157.cpp
 *
 *    Description:  Tariff
 *
 *        Version:  1.0
 *        Created:  08/30/2016 15:43:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int t, c=0, n, callTime;
    long long mile, juice;

    scanf("%d",&t);

    while (c++<t){
        scanf("%d",&n);
        mile=0, juice=0;

        while (n--){
            scanf("%d",&callTime);
            mile += (callTime/30 + 1);
            juice += (callTime/60 +1);
        } 

        mile *=10, juice *=15;

        if (mile==juice){
            printf("Case %d: Mile Juice %lld\n",c,mile);
        } else if (mile<juice){
            printf("Case %d: Mile %lld\n",c,mile);
        } else {
            printf("Case %d: Juice %lld\n",c,juice);
        }
    }
}
