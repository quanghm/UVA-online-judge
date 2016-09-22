/*
 * =====================================================================================
 *
 *       Filename:  10258.cpp
 *
 *    Description:  Contest Scoreboard
 *
 *        Version:  1.0
 *        Created:  09/15/2016 13:42:55
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
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> numSolved(101);
vector<long long> timeSolved(101);

bool compare(int i, int j){
    return ( (numSolved[i]>numSolved[j]) || 
             (   (numSolved[i]==numSolved[j]) && 
                 (     (timeSolved[i]<timeSolved[j]) || 
                       (timeSolved[i]==timeSolved[j] && i < j) 
                 )
             ) 
           );
}
int main(){
    char ch=0;
    int numCases,index;
    string line;

    cin>>numCases;
    getline(cin,line), getline(cin,line);

    for (;;){
        fill(numSolved.begin(), numSolved.end(),0);
        fill(timeSolved.begin(),timeSolved.end(),0);
        long long timeSoFar[101][10]={};
        bool isSolved[101][10]={};
        bool hasSubmission[101]={};

        while (getline(cin,line) && line.length()){
            //            cout<<line<<"\n";
            index=0;
            int buff[3]={};
            for (string::iterator it=line.begin();
                    it!=line.end();it++){
                switch (*it){
                    case ' ':
                        index++;
                        break;
                    case 'I': // wrong answer;
                        if (!isSolved[buff[0]][buff[1]])
                        {
                            timeSoFar[buff[0]][buff[1]] += 20;
                        }
                        hasSubmission[buff[0]]=1;
                        break;
                    case 'C': // correct answer;
                        if (isSolved[buff[0]][buff[1]]) break;
                        isSolved[buff[0]][buff[1]] = 1;
                        numSolved[buff[0]] ++;
                        timeSolved[buff[0]] += buff[2] + timeSoFar[buff[0]][buff[1]];

                        hasSubmission[buff[0]] = 1;
                        break;
                    case 'R':
                    case 'U':
                    case 'E':
                        hasSubmission[buff[0]] = 1;
                        break;
                    default:
                        buff[index] = buff[index]*10 + *it - '0';
                        break;
                }
            }
            //            cout<<buff[0]<<" "<<buff[1]<<" "<<buff[2]<<"---\n";
        }

        vector<int> index;
        for (int i=1; i<101; i++){
            if (hasSubmission[i]) index.push_back(i);
        }

        sort(index.begin(), index.end(), compare);

        for (vector<int>::iterator it = index.begin();
                it !=index.end(); ++it){
                cout<<*it<<" "<< numSolved[*it]<< " "<< timeSolved[*it]<<"\n";
        }

        if (--numCases){
            cout<<"\n";
        } else {
            return 0;
        }
    }
}
