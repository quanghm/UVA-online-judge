/*
 * =====================================================================================
 *
 *       Filename:  10196.cpp
 *
 *    Description:  Check the check
 *
 *        Version:  1.0
 *        Created:  09/10/2016 19:54:43
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

using namespace std;

const int knight[8]={21,19,-21,-19,-12,-8,12,8};
const int bishop[4]={-11,-9,9,11};
const int rook[4]={1,-1,10,-10};

bool check(char (&board)[120], int pos){
    char p1,p2;
    // knight
    p1 = 'k'+'N'-board[pos];
    for (int i=0; i<8; i++){
        if (board[pos+knight[i]] == p1)
            return true;
    }
    // queen or bishop
    int temp; 
    p1 = 'k'+'B'-board[pos]; // bishop
    p2 = 'k'+'Q'-board[pos]; // queen
    
    for (int i=0;i<4; i++){ // for each bishop direction
        temp=pos;
        do {
            temp += bishop[i];
        } while (board[temp]=='.');
        if (board[temp]==p1||
            board[temp]==p2) return true;
    }

    // rook or queen
    p1 = 'k'+'R'-board[pos]; // rook
    for (int i=0;i<4;i++){
        temp=pos;
        do{
            temp+=rook[i];
        } while (board[temp]=='.');
        if (board[temp]==p1|| board[temp]==p2)
            return true;
    }

    return false;
}

int main(){
    char board[120]={};
    char ch;
    int k, K, pos,game=1;

    for(;;){
        k=0,K=0,pos=21;
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                ch=getchar();
                if (ch=='k') k=pos;
                if (ch=='K') K=pos;
                board[pos++]=ch;
            }
            
            getchar(); // trailing newline
            pos+=2;
        }

        if (!k || !K) return 0;
        // blank line
        getchar();

        printf("Game #%d: ",game++);

        // black king
        // pawn
        if (board[k+11] == 'P' || board[k+9] =='P' || 
                check(board,k)) {
            printf("black king is in check.\n");
        } else if (board[K-11] == 'p' || board[K-9]=='p' ||
                check(board,K)) {
            printf("white king is in check.\n");
        } else {
            printf("no king is in check.\n");
        }
        
    }
}
