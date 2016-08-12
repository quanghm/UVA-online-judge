/*
 * =====================================================================================
 *
 *       Filename:  11752.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2016 12:59:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

//const double l=log(2);
int main(){
    int composit[] = { 2,4, 6, 8, 9,10,
                      12,14,15,16,18,
                      20,21,22,24,25,
                      26,27,28,30,32,33,
                      34,35,36,38,39,
                      40,42,44,45,46,
                      48,49,50,51,52,54,
                      55,56,57,58,60,
                      62,63,65};
    int total=0;
    unsigned long long power;
    vector<unsigned long long> superPowers;
    superPowers.push_back(1);
    
    for (long long i = 2; i< (1<<16); i++){
        int p = (int)(64 / log2(i));
//        cout<<i<<"---"<<p<<"---\n";
        unsigned long long sq=i*i;
        power = sq;

        for (int j = 1; composit[j]<= p&&j<45; ++j){
            if (composit[j]-composit[j-1] == 1){
                power *= i;
            } else if (composit[j]-composit[j-1]==2){
                power *= sq;
            } else continue;
            
//            cout<<++total<<":"<<i<<"^"<<composit[j]<<"="<<power<<"\n";
            superPowers.push_back(power);
        }
    }

    power=0;
    sort(superPowers.begin(),superPowers.end());
    for (vector<unsigned long long>::iterator it = superPowers.begin();
            it!=superPowers.end(); ++it){
        if (power==*it){
            continue;
        } else{
            power=*it;
            cout<<*it<<'\n';
        }
    }
}
