/*
 * =====================================================================================
 *
 *       Filename:  352.cpp
 *
 *    Description:  The Seasonal War -- Floodfill
 *
 *        Version:  1.0
 *        Created:  09/02/2016 11:16:32
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
#include <queue>

using namespace std;

int direction[8] = {1,-1};

void paint(int i, vector<bool>&map){
    if (map[i] == 0) return;
    map[i] = 0;
    for (int j = 0; j<8; j++){
        paint(i+direction[j], map);
    }
}
int main(){
    int dimension,count,next,c=1;
    char ch;
    while (scanf("%d",&dimension)!=EOF){
        count = 0;
        vector<bool> map( (dimension+1)*(dimension+2)+1, 0);
        direction[2] = dimension + 1, direction[3] = dimension, direction[4] = dimension +2;
        direction[5] = -direction[2], direction[6] = -direction[3], direction[7]= -direction[4];
        
        queue<int> toPaint;
        for (int i = dimension + 1; i< (dimension + 1)*(dimension + 1); i++){
            ch = getchar();
            if (ch=='1'){
                map[i] = 1, toPaint.push(i);
            }
        }

        while (!toPaint.empty()){
            next = toPaint.front(), toPaint.pop();

            if (map[next]){
                count++, paint(next,map);
            }
        }

        printf("Image number %d contains %d war eagles.\n", c++, count);
    }
}
