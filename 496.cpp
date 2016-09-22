/*
 * =====================================================================================
 *
 *       Filename:  496.cpp
 *
 *    Description:  Simply Subsets
 *
 *        Version:  1.0
 *        Created:  09/19/2016 11:55:22
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
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &v){
    for (vector<int>::iterator it = v.begin();
            it!=v.end(); it++){
        printf("%d ",*it);
    }
    printf("\n");
}

int check(vector<int>&a, vector<int>&b){
    vector<int>::iterator i1=a.begin(), i2=b.begin();
    int mode=7; // equal:
    while (i1!=a.end() && i2!=b.end()){
        if (*i1==*i2){  // A intersects B not empty
            mode = mode & 6;
            i1++; i2++;
        } else {
            break;
        }
    }

    // subsets
    if (i1==a.end()&& i2==b.end()) return 6;
    while (i1!=a.end() && i2!=b.end() && mode){
        if (*i1==*i2){ // A intersect B not empty
            mode = mode & 6;
            i1++,i2++;
        } else if (*i1<*i2){ // A\B not empty
            mode = mode & 5;
            i1++;
        } else { // *i2<*i1 -- B\A not empty
            mode = mode & 3;
            i2++;
        }
    }

    if (i1!=a.end()) { 
        mode= mode & 5; // A\B not empty
    } 
    if (i2!=b.end()){
        mode= mode & 3; // B/A not empty
    }
    return mode;
}

int main(){
    int buff;
    char ch;

    for (;;){
        if (scanf("%d",&buff)!=1) return 0;
        vector<int> a, b;

        for(;;){
            a.push_back(buff);
            if ( (ch=getchar())==10) {
                break;
            } else {
                scanf("%d", &buff);
            }
        }
        sort(a.begin(), a.end());
        // b:
        for (;;){
            scanf("%d",&buff);
            b.push_back(buff);
            if ( (ch=getchar())=='\n'||ch==EOF) break;
        }
        sort(b.begin(),b.end());
        
        switch (check(a,b)){
            case 7:
            case 6:  // 110 => A intersect B not empty, A/B and B/A are empty
                printf("A equals B\n"); 
                break;
            case 3:  // 011 => B\A not empty, A\B and (A intersects B) are empty
            case 2:  // 010 => B\A not empty and A/B is empty
                printf("A is a proper subset of B\n");
                break;
            case 5:  // 101 => A\B not empty,  B\A and (B intersects A) are empty
            case 4:  // 100 => A\B not empty and B\A is empty
                printf("B is a proper subset of A\n");
                break;
            case 0:  // 000 => A/B, B/A, and (A intersects B) are not empty
                printf("I\'m confused!\n");
                break;
            case 1: // 001 => A/B and B/A are not empty, (A intersects B) is empty
                printf("A and B are disjoint\n");
                break;
        }
    }
}
