/*
 * =====================================================================================
 *
 *       Filename:  133.cpp
 *
 *    Description:  The Dole Queue
 *
 *        Version:  1.0
 *        Created:  08/31/2016 15:19:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int n,k,m, first,second;

    while (scanf("%d%d%d", &n,&k,&m) && n){
        vector<int> pos(n);
        for (int i =1 ; i< n; i++){
            pos[i] = i;
        } 
        pos[0]=n;

        first = 1, second=0;
        for (;;){
            first = (first + k -1 ) % n;
            second = (second - m + 1)%n;
            if (second<0) second+=n;

            if (first==second){
                n--;
                if (n){
                    printf("%3d,",pos[first]);
                    pos.erase(pos.begin()+first);
                    second = (second)?(second-1):(n-1);
                } else{
                    printf("%3d\n",pos[first]);
                    break;
                }
            } else if (first>second){
                n-=2;
                if (n){
                    printf("%3d%3d,", pos[first],pos[second]);
                    pos.erase(pos.begin()+first);
                    pos.erase(pos.begin()+second);

                    first = (first-1)%n;
                    if (second){
                        second = second -1;
                    } else{ //second =0;
                        second = n-1;
                    }
                } else{
                    printf("%3d%3d\n", pos[first],pos[second]);
                    break;
                }
            } else { // second > first
                n-=2;
                if (n){
                    printf("%3d%3d,", pos[first], pos[second]);
                    pos.erase(pos.begin()+second);
                    pos.erase(pos.begin()+first);

                    second = (second==1)?(n-1):(second-2);
                } else {
                    printf("%3d%3d\n", pos[first],pos[second]);
                    break;
                }
            }
        }
    }
}
