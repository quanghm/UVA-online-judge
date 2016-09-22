/*
 * =====================================================================================
 *
 *       Filename:  10562.cpp
 *
 *    Description:  Undraw the Trees
 *
 *        Version:  1.0
 *        Created:  08/28/2016 17:01:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void drawTree(int row, int col, vector<vector<char> > & tree){
    printf("%c(",tree[row][col]);
    char ch;
    if (tree[++row][col]=='|'){
        int min=col,max=col;
        row++;
        while (tree[row][min]=='-'){
            min--;
        }
        while (tree[row][max]=='-'){
            max++;
        }
        row++;
        for (int j=min+1; j<max; j++){
            ch = tree[row][j];
            switch (ch){
                case 0:
                case ' ':
                case '#':
                case '-':
                case '|':
                    break;
                default:
                    drawTree(row,j,tree);
                    break;
            }
        }
    }
    printf(")");
}
int main(){
    int numCases,row,col;
    char ch;
    scanf("%d",&numCases),getchar();

    while (numCases--){
        vector<vector<char> > tree(201, vector<char>(201,0));
        row = 0,col=0;

        for (;;){
            // continue to get char, put into tree map
            for (col = 0;;col++){
                ch=getchar();
                if (ch=='\n'){
                    row++;
                    break;
                }
                tree[row][col]=ch;
            }
            if (col==1 && tree[row-1][0]=='#') break;
        }
        row--;
        if (row==0){
            printf("()\n");
            continue;
        }

//        for (int i=0;i<row;i++){
//            for (int j=0;;j++){
//                if (tree[i][j]) {
//                    putchar(tree[i][j]);
//                } else {
//                    putchar(10);
//                    break;
//                }
//            }
//        }
//
        col=0;
        for (;;){
            if (tree[0][col]==' ' || tree[0][col]=='|' ||
                tree[0][col]=='-' || tree[0][col]=='#'){
                col++;
            } else {break;}
        }
        printf("(");drawTree(0,col,tree);
        printf(")\n");
    }
}
