/*
 * =====================================================================================
 *
 *       Filename:  10050.cpp
 *
 *    Description:  Hartals -- Similar to Ugly Numbers
 *
 *        Version:  1.0
 *        Created:  08/25/2016 09:56:13
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
    int t, n, p, num, temp;

    scanf("%d", &t);

    while (t--){
        scanf ("%d%d", &n, &p);
        
        vector<bool> days(n+1, 0);
        int num =0;

        for (int i = 0; i< p; i++){
            scanf("%d", &temp );
            for (int j = temp; j <= n; j += temp){
                if (j%7 && j % 7 != 6 && !days[j]){
//                    printf("%d ",j);
                    num++;
                } 
                days[j] = 1;
            }   
        }
        printf("%d\n",num);
    }
}
