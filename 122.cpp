/*
 * =====================================================================================
 *
 *       Filename:  122.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/10/2016 16:11:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> val;
vector<string> pos;

// insert a string s, 
// return   -1 if found, 
//          position of next string if not found
int findString(string& s2, int l,
                vector<vector<int> > &index){
    if (l==0){ // root
        return ( (index[0].size()==1)? (-1):(0));
    }
    int ll = index[l].size();
    int i=0;
    int cmp;
    while (i<ll){
        int ii=0;
        while (ii<l){
            cmp = s2[ii] - pos[index[l][i]][ii];
            if (cmp!=0) break;
            ii++;
        }
        if (cmp==0){
            return -1;
        } else if (cmp<0){
            return i;
        }
        i++; 
    }
    return ll;
}

int main(){
    char ch;
    string s1,s2;
    bool mode; // 1-val, 0-pos
    bool isValid;
    int numNodes,p,l,maxLength;

    for (;;){
        val.clear();
        pos.clear();
        isValid = 1;
        numNodes=0;
        maxLength=0;
        vector<vector<int> > index(256); // hash string by length;
        for (;;){
            ch=getchar();
            switch (ch){
                case EOF:
                    return 0;
                    break;
                case '(':
                    s1="";
                    mode = 1;
                    break;
                case ')':
                    if (s1!="" && isValid){ //insert strings
                        val.push_back(s1), pos.push_back(s2);
                        // search for string
                        l=s2.length();

                        // length > maxNodes, invalid tree
                        if (l>255) {
                            isValid=0;
                            break;
                        }
                        if (l>maxLength) maxLength=l;
                        if ((p=findString(s2,l,index))==-1) 
                            isValid=0;
                        index[l].insert(index[l].begin()+p,numNodes);
                        
                        numNodes++;
                    }
                    break;
                case ' ':
                case 10:
                    break;
                case ',':
                    s2="";
                    mode=0;
                    break;
                default:
                    (mode)?(s1+=ch):(s2+=ch);
                    break;
            }
            if (s1=="" && ch==')'){
                break;
            }
        }

        if (index[0].size() == 0) isValid=0;

        for (int i=maxLength-1; i && isValid; i--){
            if (index[i].size() ==0) {
                isValid=0;
                break;
            }
            for (vector<int>::iterator it = index[i+1].begin();
                    it!= index[i+1].end() && isValid; it++){
                // for each string with length=i+1, search for string with
                // length i 
                vector<int>::iterator iit=index[i].begin();
                while (iit!=index[i].end()) {
                    int ii=0;
                    while (ii<i && pos[*it][ii] == pos[*iit][ii]){
                        ii++;
                    }
                    if (ii==i) break;
                    iit++;
                }
                if (iit==index[i].end()) isValid=false;
            }
        }
        
        if (!isValid) {
            cout<<"not complete\n";
            continue;
        }
        
        for (vector<vector<int> >::iterator it=index.begin();
                it!=index.end(); ++it){
            for (vector<int>::iterator iit= (*it).begin();
                    iit!=(*it).end(); ++iit){
                cout<<val[*iit]<<( (--numNodes)?(" "):("\n"));
            }
        }
    }
}
