/*
 * =====================================================================================
 *
 *       Filename:  10315.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/10/2016 16:36:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, char> card;

void readHand(vector<card> &hand);
int evalHand(vector<card> &hand);

int main(){
    char ch=10;
    vector<card> black(5);
    vector<card> white(5);
    int sb,sw;

    while (1){
        // read black hand
        readHand(black);
        sb = evalHand(black);
        // read white hand
        readHand(white);
        sw = evalHand(white);

        if (white>black) {
            printf("White wins.\n");
        } else if (white<black){
            printf("Black wins.\n");
        } else {
            printf("Tie.\n");
        }
    }
}

int evalHand(vector<card> &hand){
    int r = 0;
    sort(hand.begin(),hand.end());

    int type;
    // type:
    // 9 : straight flush
    // 8: four of a kind
    // 7: full house
    // 6: flush
    // 5: straight
    // 4: three of a kind
    // 3: two pairs
    // 2: pair
    // 1: high card
}
