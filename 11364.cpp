/*
 * =====================================================================================
 *
 *       Filename:  11364.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2016 09:38:02
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
    int t, n;

    // read the number of test cases
    scanf("%d",&t);

    // for each test case
    while (t--){
        scanf("%d",&n);
        int house, min = 100, max = 0;
        while (n--){
            scanf("%d",&house);
            if (house<min) min = house;
            if (house>max) max = house;
        }

        printf("%d\n",(max-min)*2);
    }
}
