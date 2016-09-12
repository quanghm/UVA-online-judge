/*
 * =====================================================================================
 *
 *       Filename:  11588.cpp
 *
 *    Description:  Image Coding
 *
 *        Version:  1.0
 *        Created:  09/06/2016 22:48:47
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

using namespace std;

int main(){
    int numCases,c=0;

    int r,cc,m,n;
    int max, maxCount;
    
    string line;
    cin >> numCases;
    while (c++<numCases){
        cin>> r >> cc>> m>> n;

        int count[91] = {};
        max = 0;
        maxCount=0;

        getline(cin,line);
        for (int i = 0; i<r; i++){
            getline(cin,line);

            for (string::iterator it=line.begin();
                    it!=line.end();++it){
                count[*it]++;
            }
        }
        for (int i = 'A'; i<91; i++){
            if (max<count[i]){ // new max
                max = count[i];
                maxCount = 1;
            } else if (max==count[i]){
                maxCount ++;
            }
        }
        
        maxCount *= max;
        cout<<"Case "<<c<<": "<< maxCount*m + (r*cc-maxCount)*n<<"\n";
//        cout<<max<< "---"<< maxCount<<"\n";
    }
}
