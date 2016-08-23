/*
 * =====================================================================================
 *
 *       Filename:  1586.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2016 22:52:21
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
#include <iostream>
#include <string>
using namespace std;

const double weights[]={12.01,1.008,16.00, 14.01};

int main(){
    int numCases,numAtom;
    char ch=0;
    string nuclear;
    double totalWeight;
    
    cin>>numCases;
    
    while (numCases--){
        totalWeight=0;
        cin>>nuclear;
        int t = 0, l=nuclear.length();

        while (t<l){
            ch=nuclear[t];
            numAtom = 0;
            while (++t<l && nuclear[t]>47 && nuclear[t]<58){
                numAtom = numAtom*10 + nuclear[t] - '0';
            }
            if (numAtom==0){ numAtom=1;}
            
            switch (ch){
                case 'C':
                    totalWeight+=weights[0]*numAtom;
                    break;
                case 'H':
                    totalWeight+=weights[1]*numAtom;
                    break;
                case 'O':
                    totalWeight+=weights[2]*numAtom;
                    break;
                case 'N':
                    totalWeight+=weights[3]*numAtom;
                    break;
            }
        }
        printf("%.03lf\n",totalWeight);
    }
}
