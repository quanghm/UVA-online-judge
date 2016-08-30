/*
 * =====================================================================================
 *
 *       Filename:  11683.cpp
 *
 *    Description:  Laser Sculpture
 *
 *        Version:  1.0
 *        Created:  08/29/2016 01:11:23
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

using namespace std;

int main(){
    int h, l, maxHeight,temp,prev;
    long long sum;

    //int heights[10001];

    while ((cin>> h >> l)&& h){
        cin>> prev;
        temp=prev,sum =0;
        for (int i = 1; i<l; i++){
            //read 
            cin>> temp;
            //if (temp> maxHeight) maxHeight=temp;
            if (temp>prev) sum+=(temp-prev);
            prev = temp;
        }
        
        sum += (h-temp);

        cout<<sum<<"\n";
    }
}
