/*
 * =====================================================================================
 *
 *       Filename:  10344.cpp
 *
 *    Description:  23 out of 5
 *
 *        Version:  1.0
 *        Created:  08/29/2016 09:12:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

int numPer[120][5];
int numbers[5];
int result[5];

void op(int& num1, int&num2, int& r, int &op){
    switch (op){
        case 0: 
            r = num1 + num2;
            break;
        case 1:
            r = num1 - num2;
            break;
        case 2:
            r = num1 * num2;
            break;
    }
}

void get23(){
    long long s;
    for (int i = 0; i<120; i++){
        result[0]=numbers[numPer[i][0]];
        for (int o1 = 0; o1<3; o1++){
            op(result[0],numbers[numPer[i][1]],result[1],o1);
            for (int o2=0; o2<3; o2++){
                op(result[1],numbers[numPer[i][2]],result[2],o2); 
                for (int o3=0; o3<3;o3++){
                    op(result[2],numbers[numPer[i][3]],result[3],o3);
                    for (int o4=0; o4<3; o4++){
                        op(result[3],numbers[numPer[i][4]],result[4],o4); 
                        if (result[4]==23) {
                            cout<<"Possible\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    cout<<"Impossible\n";
}
int main(){
    for (int i = 0; i< 5; ++i){
        numbers[i] = i;
    }

    int temp=0;

    // get permutation;
    do {
        for (int i=0; i<5; ++i){
            numPer[temp][i] = numbers[i];
        }
        temp++;
    } while (next_permutation(numbers, numbers+5));

    for (;;){
        for (int i = 0; i<5; i++){
            cin>> numbers[i];
        }
        if (numbers[0]==0) break;
        get23();
    }
}
