/*
 * =====================================================================================
 *
 *       Filename:  1262.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/14/2016 18:46:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int t, k;

    string code;
    
    cin >> t;

    while (t--){
        cin>> k;
        vector<vector<char> > dict(5);
        vector<vector<bool> > isRepeated(5,vector<bool>(26,0));
        int l[5];
        int s=1;

        // read the first 6 lines
        for (int i =0; i<6; ++i){
            cin>>code;
            for (int j=0;j<5;++j){
                isRepeated[j][code[j]-'A']=1;
            }
        }

        // read secon 6 lines and check for duplicate
        for (int i=0; i<6;++i){
            cin >> code;
            for (int j=0;j<5;++j){
                if (isRepeated[j][code[j]-'A']) {
                    dict[j].push_back(code[j]);
                    isRepeated[j][code[j]-'A']=0;
                }
            }
        }

        // sort 
        for (int j=0; j<5; ++j){
            sort(dict[j].begin(),dict[j].end());
            l[j]=dict[j].size();
//            for (int i = 0; i<l[j];i++){
//                cout<<dict[j][i];
//            }
//            cout<<"--\n";
            s *= l[j];
        }

        if (k>s){
            cout<<"NO\n";
            continue;
        }
        k--; 
        char ans[5];
        for (int j =0;j<5;++j){
            s /= l[j];
            ans[j] = dict[j][k/s];
            k%=s;
        }
        
        for (int j=0;j<5;++j){
            cout<<ans[j];
        }
        cout<<'\n';
    }    
}
