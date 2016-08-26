/*
 * =====================================================================================
 *
 *       Filename:  572.cpp
 *
 *    Description:  Oil Deposits
 *
 *        Version:  1.0
 *        Created:  08/25/2016 11:25:23
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
#include <queue>

using namespace std;

int direction[8] = {0,0,0,0,0,0,1,-1};

void floodFill(int start, vector<int>&color){
    if (!color[start]) return;

    color[start] = 0;

    for (int i=0;i<8;i++){
        floodFill(start+direction[i],color);
    }
    return;
}

int main(){
    int m,n, temp;
    char ch;
    while (scanf("%d%d",&m,&n) && m){
        getchar(); // get rid of trailing new line character
        vector<int> color( (m+2) * (n+1)+1, 0);
        queue<int> toPaint;
        int numRegions=0;

        direction[0] = n+1;                     // s
        direction[1] = -n-1;                    // n
        direction[2] = n;                       // sw
        direction[3] = n+2;                     // se
        direction[4] = -n;                      // ne
        direction[5] = -n-2;                    //nw

        temp=n+2;
        for (int r=0; r<m; ++r){
            for (int j = 0; j<=n; j++){
                ch=getchar();
//                putchar(ch);
                if (ch=='@') {
                    color[temp] = 1;
                    toPaint.push(temp);
                }
                temp++;

            }
        }

//        for (int r=0; r<=m+1; ++r){
//            for (int c = 0; c<=n ; ++c){
//                printf("%d",color[r*(n+1)+c]);
//            }
//            printf("\n");
//        }
//        printf("---\n");

        // paint
        while (!toPaint.empty()){
            temp = toPaint.front();
            toPaint.pop();

            if (color[temp]){
                numRegions++;
                floodFill(temp,color);
            }
        }
        printf("%d\n",numRegions);
    }
}
