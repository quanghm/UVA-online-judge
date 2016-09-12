/*
 * =====================================================================================
 *
 *       Filename:  130.cpp
 *
 *    Description:  Roman Roulette
 *
 *        Version:  1.0
 *        Created:  08/12/2016 20:01:58
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
#include <vector>

using namespace std;
//int findLast(int n, int k){
//    if (n==1) return 0;
//    if (n==2) return 1-(k%2);
//
//    int i = findLast(n-1,k);// start at 0
//    return (i+k-1)%(n-1); // start at k
//}
//
//void print(vector<int> &v){
//    for (vector<int>::iterator it = v.begin();
//            it!=v.end(); it++){
//        cout<<*it<<" ";
//    }
//    cout<<"\n";
//}
//
int main(){
    int n, k, killed, moved, start,temp;

    while (cin>>n>>k&&n){
    
        if (n==1){
            cout<< "1\n";
            continue;
        }
        
        vector<int> people(n);
        temp =n;

        for (int i = 0; i<n; i++){
            people[i] = i;
        }
        people[0]=n;

        start = 0;
        for(;;){
            killed = (start+k-1) % n;

            people.erase(people.begin()+killed);

            n--;
            if (n==1) break;
            moved = (killed + k-1) % n;
            people.insert(people.begin()+killed, people[moved]);

            if (moved>=killed){
                people.erase(people.begin()+moved+1);
                start = killed+1;
            } else{
                people.erase(people.begin()+moved);
                start = killed;
            }
//            print(people);
        }
        
        cout<< temp - people[0]+1<<"\n";
    }
}
