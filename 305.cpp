/*
 * =====================================================================================
 *
 *       Filename:  305.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2016 10:47:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k, k2, m, start;
    int val[14];
    for (k= 1;k<14; k++){
        k2 = k*2;
        vector<int> circle(k2);
        vector<int> line;
        for (int i =0; i<k2; i++){
            circle[i] = i;
        }
        
        bool flag = true;
        m = k;
        while (flag){
            line = circle;
            k2 = 2*k;
            start = 0;
            while (k2>k && flag){
                // print
//                cout<<k<<":::"<< m<<"\n";
//                for (vector<int>::iterator it = line.begin(); it !=line.end(); ++it){
//                    cout<< *it<< " ";
//                } 
//                cout<<"___\n";
                start = (start + m) % k2;
                
                if (line[start] < k) {
                    break;
                }

                line.erase(line.begin() + start);
                k2--;
            }
            m++;
            if (k2==k) {
                val[k]=m;
                break;
            }
        }
    }
    while (cin>>k && k){
        cout<<val[k]<<"\n";
    }
}

