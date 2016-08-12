/*
 * =====================================================================================
 *
 *       Filename:  11559.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2016 10:57:34
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
    int n, // number of guests 
        b, // b
        h, // number of hotels
        w, // number of possible weeks
        p, // price per person
        a; // number of available beds 
    while (cin>>n){
        cin >> b >> h >> w;

        int sum = b+1;

        // read through the hotel list
        while (h--){

            // read the price per peson for that hotel
            cin >> p;
            int temp;

            // for each of the weekend
            for (int i=0;i<w;++i){
                cin >> a;
                // if the available beds >= number of persons
                if (a>=n){
                    temp = p*n;
                    if (temp<sum) sum = temp;
                }
            }
        }

            // check if sum is below b
            if (sum > b){
                cout<<"stay home\n";
            } else {
                cout<<sum<<"\n";
            }
    }
}
