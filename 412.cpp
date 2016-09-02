/*
 * =====================================================================================
 *
 *       Filename:  412.cpp
 *
 *    Description:  Pi
 *
 *        Version:  1.0
 *        Created:  09/01/2016 16:24:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int primes[42]={ 
      2,  3,  5,  7, 11, 13, 17, 19, 23, 29, 
     31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
     73, 79, 83, 89, 97,101,103,107,109,113, 
    127,131,137,139,149,151,157,163,167,173, 
    179, 181};

void factorize(int temp, int i, vector<vector<int> >& divisors);
int isRelativePrime(int i, int j, vector<vector<int> >&divisors);

int main(){
    int N, temp, numRelativePrimePairs;
    double estimate;

    while (scanf("%d",&N) && N){
        vector<vector<int> > divisors(N);
        numRelativePrimePairs = 0;
        for (int i = 0; i<N; i++){
            scanf("%d",&temp);

            factorize(temp, i, divisors);

            for (int j=0; j<i; j++){
                numRelativePrimePairs += isRelativePrime(i,j,divisors);
            }
        }

        if (numRelativePrimePairs){
            estimate = sqrt(N * (N-1) * 3.0 / numRelativePrimePairs);
            printf("%.06lf\n",estimate);
        } else{
            printf("No estimate for this data set.\n");
        }
    }
}

void factorize(int temp, int i, vector<vector<int> >& divisors){
    int remainder;
    for (int j = 0; j<42 && temp>primes[j]; j++){
        remainder = temp % primes[j];

        if (remainder) continue;
        divisors[i].push_back(primes[j]);
        while (remainder==0){
            temp /=primes[j];
            remainder = temp % primes[j];
        }

    }
    if (temp > 1) divisors[i].push_back(temp);
}

int isRelativePrime(int i, int j, vector<vector<int> > &divisors){
    vector<int>::iterator i1 = divisors[i].begin(),
        i2 = divisors[j].begin();

    while (i1!=divisors[i].end() && i2 !=divisors[j].end()){
        if (*i1==*i2) return 0;
        if (*i1 < *i2) {
            i1++;
        } else {
            i2++;
        }
    }
    return 1;
}
