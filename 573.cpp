/*
 * =====================================================================================
 *
 *       Filename:  573.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 15:44:42
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
    int H, U, D, F;
    double upRate,currentHeight,fatigue;

    while ((cin >> H >> U >> D >>F) && (H)){
        int days = 1;
        fatigue = U * F / 100.0;
        currentHeight = 0;
        upRate = U;

        while (1){
            // climb up if upRate is positive
            if (upRate>0){
                currentHeight += upRate;
            } 
            if (currentHeight>H){
                cout<<"success on day "<<days<<"\n";
                break;
            }
            
            // slide down:
            currentHeight -= D;
            if (currentHeight<0){
                cout<<"failure on day "<< days<<"\n";
                break;
            }

            // update upRate
            if (upRate > fatigue){
                upRate-= fatigue;
            }else{
                upRate =0;
            }
            ++days;
        }
   }
}
