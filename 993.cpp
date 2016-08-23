/*
 * =====================================================================================
 *
 *       Filename:  993.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/23/2016 02:09:51
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
    int t,n;
    int primes[4]={2,3,5,7};

    cin>>t;

    while (t--){
        cin>>n;

        if (n<10){
            cout<< n<<"\n";
            continue;
        }

        int powers[4] ={}; // 2 3 5 7

        for (int i=0; i<4;++i){
            while (n % primes[i]==0){
                powers[i]++;
                n/=primes[i];
            }
        }
        
        if (n!=1){
            cout<<"-1\n";
            continue;
        }

        int numDigits[10]={};
        numDigits[9] = powers[1]/2;
        numDigits[3] = powers[1]%2;

        numDigits[8] = powers[0]/3;
        numDigits[2] = powers[0]%3;

        numDigits[5] = powers[2];
        numDigits[7] = powers[3]; 

        if (numDigits[2] && numDigits[3]){
            numDigits[6]=1;
            numDigits[2]--;
            numDigits[3] = 0;
        }

        numDigits[4] = numDigits[2]/2;
        numDigits[2] %= 2;

        for (int i=2;i<10;i++){
            for (int j=0;j<numDigits[i];j++){
                cout<<i;
            }
        }
        cout<<"\n";
    }
}
