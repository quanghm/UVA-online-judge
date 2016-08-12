/*
 * =====================================================================================
 *
 *       Filename:  10550.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 16:19:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
    int initial, first, second, third;
    int degrees, increment;

    while ((cin>> initial >> first >> second >> third)&&(initial || first || second || third)){
        // two full turns
        degrees = 720;

        // continue clockwise -- number is decreasing
        increment = (initial>first) ? (initial - first) : (40+initial - first);
        degrees += increment*9;

        // now one full turn counter-clockwise
        degrees +=360;
        
        // continue on counter-clockwise -- number is increasing
        increment = (second > first) ? (second - first) : (40 + second - first);
        degrees += increment*9;

        // continue on clockwise -- number is decreasing
        increment = (second>third)? (second-third) : (40+second - third);
        degrees += increment*9;

        cout<< degrees << "\n";

    
    }
}
