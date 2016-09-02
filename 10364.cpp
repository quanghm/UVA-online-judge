/*
 * =====================================================================================
 *
 *       Filename:  10364.cpp
 *
 *    Description:  Square
 *
 *        Version:  1.0
 *        Created:  08/31/2016 22:35:42
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
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sticks;
unsigned int numSticks;

// find all subset from sticks that sum to sum
vector<unsigned int> getSubsetWithSum(unsigned int start, unsigned int  sum){
    
    if (start==numSticks) {
        vector<unsigned int> r;
        return r;
    }
    if (sum < sticks[start]) {
        vector<unsigned int> r;
        return r;
    }

    vector<unsigned int> r = getSubsetWithSum(start+1,sum);

    if (sticks[start] == sum){
        r.push_back(1 << start);
        return r;
    }
    
    vector<unsigned int> v = getSubsetWithSum(start+1,sum-sticks[start]);
    for (vector<unsigned int>::iterator it = v.begin();
            it!=v.end();++it){
        *it += (1 << start);
        r.push_back(*it);
    }
    return r;
}

void print(unsigned int k){
    for (unsigned int i =0; i<numSticks; i++){
        if (k & (1<<i)) {
            printf("%3u",sticks[i]);
        } else{
            printf("   ");
        }
    }
    cout<<"\n";
}

int main(){
    unsigned int numCases,  totalLength,  subset;

    cin>>numCases;

    while (numCases--){
        cin>> numSticks;
        sticks.resize(numSticks);
        totalLength=0;

        for (unsigned int i = 0; i<numSticks; i++){
            cin>>sticks[i];
            totalLength += sticks[i];
        }


        if (totalLength % 4) {
            cout<<"no\n";
            continue;
        }

        sort(sticks.begin(),sticks.end());


        vector<unsigned int> r = getSubsetWithSum(0, totalLength/4);

//        for (vector<unsigned int>::iterator it = r.begin(); it < r.end(); it++){
//            print(*it);
//        }
//
        bool flag = true;

        for (vector<unsigned int>::iterator i1= r.begin(); i1 != r.end() && flag; i1++){
            for (vector<unsigned int>::iterator i2 = i1+1; i2 < r.end() && flag; i2++){
                if (*i2 & *i1) continue;
                subset= *i1 | *i2;
                for (vector<unsigned int>::iterator i3 = i2+1; i3 < r.end(); i3++){
                    if (*i3 & subset) {
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag) {
            cout<<"no\n";
        } else{
            cout<<"yes\n";
        }
    }
}
