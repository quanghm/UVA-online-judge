/*
 * =====================================================================================
 *
 *       Filename:  200.cpp
 *
 *    Description:  Rare order
 *
 *        Version:  1.0
 *        Created:  09/01/2016 09:36:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void visit(char i, 
            vector<bool> &isInList, 
            vector<vector<bool> > &order, 
            vector<char> &orderedList){
    if (!isInList[i]) return;
    isInList[i] = 0;

    for (int j = 0; j<26; j++){
        if (order[i][j]) visit(j, isInList, order, orderedList);
    }
    orderedList.push_back(i+'A');
}

int main(){
    string s1, s2;
    string::iterator i1, i2;
    for (;;){
        if(!(cin>> s1) ) break;
//        if (s1.length() == 0) break;
        
        vector<bool> isInList(26,0);
        vector<vector<bool> > order(26,vector<bool>(26));
        
        for (i1 = s1.begin(); i1 != s1.end(); i1++){
            isInList[*i1-'A'] = 1;    
        }

        // build the orders
        for(;;){
            cin>>s2;
            if (s2[0] == '#') break;

            for (i2 = s2.begin(); i2 != s2.end(); i2++){
                isInList[*i2-'A'] = 1;
            }

            // compare two strings
            i1=s1.begin(), i2=s2.begin();
            
            while (*i1 == *i2) {
                i1++, i2++;
            }

            if ( *i1 && *i2 ){ // no string at end
                order[*i1-'A'][*i2 - 'A'] = 1;
            }
            swap(s1, s2);
        }

        // get the ordered list
        vector<char> orderedList;
        for (char i = 0; i< 26; i++){
            visit(i,isInList, order, orderedList);
        }

        // print
        for (vector<char>::reverse_iterator rit = orderedList.rbegin();
                rit != orderedList.rend(); rit++){
            cout<< *rit;
        }
        cout<<"\n";
    }
}
