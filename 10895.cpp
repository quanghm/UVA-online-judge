/*
 * =====================================================================================
 *
 *       Filename:  10895.cpp
 *
 *    Description:  Matrix transpose
 *
 *        Version:  1.0
 *        Created:  08/12/2016 15:43:43
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

bool compareVec(vector<int>& a, vector<int>&b){
    return (a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]));
}

int main(){
    int m,n;
    int val, numNonZero;
    vector<int> cols(80);

    while (cin>>m>>n){
        vector<vector<int> > mat;
        
        // read the matrix
        for (int j = 1; j<=m; ++j){
            // get number of non zero entries on the row
            cin>> numNonZero;
            
            // get the non zero entries
            for (int i = 0; i<numNonZero; ++i){
                cin>>cols[i];
            }

            // get the non-zero values
            for (int i = 0; i<numNonZero; ++i){
                cin>>val;
                // insert the entry
                vector<int> v(3);
                v[0]=cols[i],v[1]=j,v[2]=val;
                mat.push_back(v);
            }
        }

        // sort mat to get the transpose matrix:
        sort(mat.begin(),mat.end(),compareVec);
    

        // print the transpose matrix
        cout<< n <<' '<< m<<'\n';
        val = mat.size();

        if (val==0){
            for (int i=0;i<n;++i){
                cout<<"0\n\n";
            }
            continue;
        }
        int row = 1;
        int head = 0,tail;

        for(;;){
            while (row<mat[head][0]){
                cout<<"0\n\n";
                row++;
            }
            // print row
            tail=head;
            while (tail<val&&mat[head][0]==mat[tail][0]){
                tail++;
            }

            // print number of non-zero entries
            cout<<tail - head;
            for (int i = head; i<tail; ++i){
                cout<<' '<<mat[i][1];
            }
            cout<<'\n';
            for (int i = head; ; ){
                cout<<mat[i][2];
                if (++i==tail){
                    cout<<'\n';
                    break;
                } else {
                    cout<<' ';
                }
            }
            if (tail==val) {
                while (row++<n){
                    cout<<"0\n\n";
                }
                break;
            }
            head=tail;row++;
        
        }
    }
}
