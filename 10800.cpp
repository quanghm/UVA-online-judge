/*
 * =====================================================================================
 *
 *       Filename:  10800.cpp
 *
 *    Description:  Not That Kind of Graph
 *
 *        Version:  1.0
 *        Created:  08/23/2016 00:45:09
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
#include <string>
#include <vector>

using namespace std;

int main(){
    int n,x=0, minAtt, maxAtt, length,level;

    cin>> n;

    while (x++<n){
        string stock;
        cin>>stock;
        cout<<"Case #"<<x<<":\n";

        length = stock.length();
        minAtt=50, maxAtt=50, level=50;

        vector<vector<int> > lines(101,vector<int>());

        for (int i=0; i<length; ++i){
            switch (stock[i]){
                case 'R':
                    lines[level].push_back(i);
                    level++;
                    if (level>maxAtt){
                        maxAtt=level;
                    }
                    break;
                case 'C':
                   lines[level].push_back(i);
                   break;
                case 'F':
                   level--;
                   lines[level].push_back(i);
                   if (level<minAtt){
                       minAtt=level;
                   }
                   break;
            }
        }

        if (lines[maxAtt].size()==0){
            maxAtt--;
        }

        while (maxAtt>=minAtt){
            cout<<"| ";
            level=0;
            for(vector<int>::iterator it = lines[maxAtt].begin();
                    it!=lines[maxAtt].end();++it){
                while (level++<*it){
                    cout<<" ";
                }

                switch(stock[*it]){
                    case 'R':
                        cout<<'/';
                        break;
                    case 'C':
                        cout<<'_';
                        break;
                    case 'F':
                        cout<<'\\';
                        break;
                }
            }
            cout<<"\n";
            maxAtt--;
        }
        cout<<"+--";
        for (int i=0;i<length;++i){
            cout<<'-';
        }
        cout<<"\n\n";
    }
}
