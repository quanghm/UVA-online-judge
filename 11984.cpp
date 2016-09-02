/*
 * =====================================================================================
 *
 *       Filename:  11984.cpp
 *
 *    Description:  A Change in Thermal Unit
 *
 *        Version:  1.0
 *        Created:  08/31/2016 09:33:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<cstdio>

using namespace std;

int main(){
    int t, caseNum=0, celcius, increment;

    scanf("%d",&t);

    while (caseNum++<t){
        scanf("%d%d", &celcius, &increment);

        // increment in fahrenheit, change to celcius
        increment *= 5; 
        celcius += increment/9;
        increment %= 9;

        increment = (increment * 1000 / 9 +5)/10;
        printf("Case %d: %d.%02d\n",caseNum, celcius, increment);
    }
}
