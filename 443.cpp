/*
 * =====================================================================================
 *
 *       Filename:  443.cpp
 *
 *    Description:  Humble Numbers
 *
 *        Version:  1.0
 *        Created:  09/01/2016 11:46:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int d[4] = {2,3,5,7};

vector<unsigned int> m(4);

bool compare(int i, int j){
    return (m[i]<m[j]);
}

int main(){
    unsigned int num[5843]={0,1,2,3,4,5,6};

    vector<int> index(4);

    for (int i=0;i<4;i++){
        index[i] = i;
    }

    unsigned int count = 7, r;
    unsigned int head[4] = {4,3,2,1};

    while (count<5843){
        // get new multiplication
        for (int i =0; i<4; ++i){
            m[i] = num[head[i]] * d[i];
        }

        // check if any multiplications is repeated
        for (int i = 0; i<4; ++i){
            for (int j = i+1; j<4; ++j){
                if (m[i]==m[j]){
                    m[j] = num[++head[j]] * d[j];
                }
            }
        }

        // sort the new array
        sort(index.begin(), index.end(), compare);
        num[count++] = m[index[0]], head[index[0]]++;
    }

    while (cin>>count && count){
        // get ordinal
        r = count % 100;
        if (r<19 && r>10){
            cout<<"The "<<count<<"th humble number is "<< num[count]<<".\n";
            continue;
        }

        r %=10;
        switch (r){
            case 1:
                cout<<"The "<<count<<"st humble number is "<< num[count]<<".\n";
                break;
            case 2:
                cout<<"The "<<count<<"nd humble number is "<< num[count]<<".\n";
                break;
            case 3:
                cout<<"The "<<count<<"rd humble number is "<< num[count]<<".\n";
                break;
            default:
                cout<<"The "<<count<<"th humble number is "<< num[count]<<".\n";
                break;
        }
    }
}
